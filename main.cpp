#include <iostream>
#include <string>
#include <curl/curl.h>

const std::string TWILIO_ACCOUNT_SID = "ACadd67858c29e348e0bbd464213c569b0";
const std::string TWILIO_AUTH_TOKEN = "3f61f347d6832696550c200f28540f9f";
const std::string TWILIO_PHONE_NUMBER = "+15736794954";
const std::string SMS_RECIPIENT_NUMBER = "+916386205855";

std::string urlencode(const std::string &s) {
  static const char *hex = "0123456789ABCDEF";
  std::string ret;
  for (auto c : s) {
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')) {
      ret += c;
    } else {
      ret += '%';
      ret += hex[c >> 4];
      ret += hex[c & 15];
    }
  }
  return ret;
}

int main() {
  CURL *curl;
  CURLcode res;
  std::string url = "https://api.twilio.com/2010-04-01/Accounts/" + TWILIO_ACCOUNT_SID + "/Messages.json";
  std::string message = "C++ App : Tested by Vimlesh Kumar Kanaujiya";
  std::string post_fields = "From=" + TWILIO_PHONE_NUMBER + "&To=" + SMS_RECIPIENT_NUMBER + "&Body=" + urlencode(message);

  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields.c_str());
    curl_easy_setopt(curl, CURLOPT_USERNAME, TWILIO_ACCOUNT_SID.c_str());
    curl_easy_setopt(curl, CURLOPT_PASSWORD, TWILIO_AUTH_TOKEN.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      std::cerr << "Failed to send SMS: " << curl_easy_strerror(res) << std::endl;
    }

    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
  return 0;
}
