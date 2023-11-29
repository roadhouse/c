#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

char* build_shodan_url(char* search_query) {
  const char* base_url = "https://api.shodan.io/shodan/host/search?key=%s&query=%s";
  const char* shodan_api_key = getenv("SHODAN_API_KEY");
  const int total = strlen(base_url) + strlen(shodan_api_key) + strlen(search_query);
  char* url = (char*) malloc(total * sizeof(char));

  sprintf(url, base_url, shodan_api_key, search_query);

  return url;
}
 
/* compiling: gcc getcurl.c -o getcurl -lcurl */
int main(int argc, char *argv[])
{
  char* search_query = "android%20debug%20bridge%20product:%22Android%20Debug%20Bridge%22";
  char* final_size = build_shodan_url(search_query);
  printf("FINAL URL: %s\n", final_size);

  return 0;
  /* CURL *curl; */
  /* CURLcode res; */
 
  /* curl = curl_easy_init(); */

  /* if(curl) { */
    /* "https://api.shodan.io/shodan/host/search?key=$api&query=android debug bridge" */
    /* wget "https://api.shodan.io/shodan/host/search?key=$api&query=android%20debug%20bridge%20product:%22Android%20Debug%20Bridge%22&facets={facets}&page=$i" */

    /* curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com"); */
    /* curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); */

    /* res = curl_easy_perform(curl); */

    /* if(res != CURLE_OK) */
      /* fprintf(stderr, "curl error: %s\n", curl_easy_strerror(res)); */

    /* curl_easy_cleanup(curl); */
  /* } */

}
