#include <iostream>
#include <string>

using namespace std;

class CompanyConfig {
private:
  string companyName;
  string supportEmail;
  string website;
  string contactLink;
  string companyAddress;

  // Private constructor
  CompanyConfig() {
    cout << "CompanyConfig object created!\n";
    companyName = "TechNova";
    supportEmail = "support@technova.com";
    website = "https://technova.com";
    contactLink = "https://linktr.ee/technova";
    companyAddress = "Bengaluru, India";
  }

public:
  // Get the single instance
  static CompanyConfig& getInstance() {
    static CompanyConfig instance;
    return instance;
  }

  void setCompanyName(const string& name) {
      companyName = name;
  }

  string getCompanyName() const {
      return companyName;
  }

  string getSupportEmail() const {
      return supportEmail;
  }

  string getWebsite() const {
      return website;
  }

  string getContactLink() const {
      return contactLink;
  }

  string getCompanyAddress() const {
      return companyAddress;
  }
};

int main() {

    // Both refer to the same object
    CompanyConfig& config1 = CompanyConfig::getInstance();
    CompanyConfig& config2 = CompanyConfig::getInstance();

    // Change using config1
    config1.setCompanyName("TechNova India");

    cout << "\n--- Company Configuration ---\n";
    cout << "Company Name : " << config2.getCompanyName() << '\n';
    cout << "Support Email: " << config2.getSupportEmail() << '\n';
    cout << "Website      : " << config2.getWebsite() << '\n';
    cout << "Contact Link : " << config2.getContactLink() << '\n';
    cout << "Address      : " << config2.getCompanyAddress() << '\n';

    // Prove both references point to the same object
    cout << "\n--- Singleton Test ---\n";

    if (&config1 == &config2)
        cout << "SUCCESS: Both references point to the same object.\n";
    else
        cout << "ERROR: Different objects created.\n";

    cout << "\nAddress of config1: " << &config1 << '\n';
    cout << "Address of config2: " << &config2 << '\n';

    return 0;
}
