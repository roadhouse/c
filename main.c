#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

char* build_shodan_url(char* search_query) {
  const char* base_url = "https://api.shodan.io/shodan/host/search?key=%s&query=%s";
  const char* shodan_api_key = getenv("SHODAN_API_KEY");
  char* url = (char*) malloc(strlen(base_url) + strlen(shodan_api_key) + strlen(search_query));

  sprintf(url, base_url, shodan_api_key, search_query);

  return url;
}

void fetch_shodan_data(char* url) {
  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();

  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
      fprintf(stderr, "curl error: %s\n", curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
}

char* shodan_data_filename() {
  srand(time(NULL));

  const char* filename_template = "shodandata-%d.json";
  const int unique_id_int = rand();
  const int unique_id_length = snprintf(NULL, 0, "%d", unique_id_int);
  char* filename = (char *) malloc(strlen(filename_template) + unique_id_length);

  sprintf(filename, filename_template, unique_id_int);

  return filename;
}

int main()
{
  char* search_query = "android%20debug%20bridge%20product:%22Android%20Debug%20Bridge%22";
  printf("shodan url: %s\n", build_shodan_url(search_query));

  printf("filename: %s\n", shodan_data_filename());

  return 0;
}
