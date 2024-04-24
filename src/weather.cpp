#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  std::string readBuffer;
  std::string str_url = "https://wttr.in/Detroit?format=j1";

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, str_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;
  }

  json j = json::parse(readBuffer);

  for (json::iterator it = j.begin(); it != j.end(); ++it) {
    std::cout << *it << '\n';
  }
  return 0;
}
