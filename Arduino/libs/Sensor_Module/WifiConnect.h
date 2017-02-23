class WifiConnect{
    private:
        int wifi_pintx;
        int wifi_pinrx;
    public:
        String getStatus(bool status);
        String getStatus(ESP8266CommandStatus status);
        String getRole(ESP8266Role role);
        String getProtocol(ESP8266Protocol protocol);
    
}