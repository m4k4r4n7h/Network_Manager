#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>

//This Script is for lazy ppl like me ;)

using namespace std;
void clear(){

	system("clear");
}
void showPrivateIP() {
    cout << "\nFetching private IP address...\n";
    system("ip a | grep inet | grep -v inet6");
}

void showPublicIP() {
    cout << "\nFetching public IP address...\n";
    system("curl ifconfig.me");
    cout<<endl;
}

void showConnectedDevices() {
    cout << "\nFetching connected devices...\n";
    system("arp -a");
}

void showNetworkInfo() {
    cout << "\nFetching detailed network information...\n";
    system("ip a");
}

void showDNSConfig() {
    cout << "\nFetching DNS configuration...\n";
    system("cat /etc/resolv.conf");
}

void showRoutingTable() {
    cout << "\nFetching routing table...\n";
    system("route -n");
}

void showNetstat() {
    cout << "\nFetching network statistics...\n";
    system("netstat");
}

void showActiveConnections() {
    cout << "\nFetching active connections...\n";
    system("netstat -an");
}

void showFirewallStatus() {
    cout << "\nFetching firewall status...\n";
    system("sudo ufw status");
}

void showNetworkAdapterStatus() {
    cout << "\nFetching network adapter status...\n";
    system("ip link show");
}

void showWiFiInfo() {
    cout << "\nFetching Wi-Fi info...\n";
    system("iw dev");
}

void showMACAddress() {
    cout << "\nFetching MAC address...\n";
    system("cat /sys/class/net/*/address");
}

void showInterfaceStats() {
    cout << "\nFetching network interface statistics...\n";
    system("netstat -i");
}

void showTCPConnections() {
    cout << "\nFetching TCP connections...\n";
    system("netstat -p tcp");
}

void showUDPConnections() {
    cout << "\nFetching UDP connections...\n";
    system("netstat -p udp");
}

void showPing(string ip) {
    cout << "\nPinging: " << ip << "...\n";
    string cmd = "ping -c 4 " + ip;
    system(cmd.c_str());
}
void shell(){
    system("sh");
}
void showTraceroute(string ip) {
    cout << "\nTracing route to: " << ip << "...\n";
    string cmd = "traceroute " + ip;
    system(cmd.c_str());
}

void showSubnetMask() {
    cout << "\nFetching subnet mask...\n";
    system("ifconfig | grep inet | grep -v inet6");
}

void showGateway() {
    cout << "\nFetching default gateway...\n";
    system("ip route show default");
}

void showAllNetworkInterfaces() {
    cout << "\nFetching all network interfaces...\n";
    system("ip a");
}
void starwar(){
    system("telnet towel.blinkenlights.nl");
}

void showWirelessNetworkInfo() {
    cout << "\nFetching wireless network information...\n";
    system("nmcli device wifi list");
}

void showHelp() {
    cout << "\nAvailable Commands:\n";
    cout << "help                      - Show this help message\n";
    cout<<  "starwar                   - watch starwar in terminal.\n";
    cout << "show private_ip           - Show private IP address\n";
    cout << "show public_ip            - Show public IP address\n";
    cout << "show connected_devices    - Show connected devices on the network\n";
    cout << "show network_info         - Show network configuration\n";
    cout << "show dns_config           - Show DNS configuration\n";
    cout << "show routing_table        - Show routing table\n";
    cout << "show netstat              - Show network statistics\n";
    cout << "show active_connections   - Show active connections\n";
    cout << "show firewall_status      - Show firewall status\n";
    cout << "show network_adapter      - Show network adapter status\n";
    cout << "show wifi_info            - Show Wi-Fi info\n";
    cout << "show mac_address          - Show MAC address\n";
    cout << "show interface_stats      - Show network interface statistics\n";
    cout << "show tcp_connections      - Show TCP connections\n";
    cout << "show udp_connections      - Show UDP connections\n";
    cout << "ping <ip_or_domain>       - Ping a host\n";
    cout << "trace <ip_or_domain>      - Trace route to a host\n";
    cout << "show subnet_mask          - Show subnet mask\n";
    cout << "show gateway              - Show default gateway\n";
    cout << "show all_interfaces       - Show all network interfaces\n";
    cout << "show wireless_networks    - Show available wireless networks\n";
    cout<<  "use shell                 - Use your linux shell\n";
    cout << "exit                      - Exit the program\n";
}

int main() {
    string input;
    string command;
    map<string, void(*)()> commandMap;

   commandMap["show private_ip"] = showPrivateIP;
    commandMap["show public_ip"] = showPublicIP;
    commandMap["show connected_devices"] = showConnectedDevices;
    commandMap["show network_info"] = showNetworkInfo;
    commandMap["show dns_config"] = showDNSConfig;
    commandMap["show routing_table"] = showRoutingTable;
    commandMap["show netstat"] = showNetstat;
    commandMap["show active_connections"] = showActiveConnections;
    commandMap["show firewall_status"] = showFirewallStatus;
    commandMap["show network_adapter"] = showNetworkAdapterStatus;
    commandMap["show wifi_info"] = showWiFiInfo;
    commandMap["show mac_address"] = showMACAddress;
    commandMap["show interface_stats"] = showInterfaceStats;
    commandMap["show tcp_connections"] = showTCPConnections;
    commandMap["show udp_connections"] = showUDPConnections;
    commandMap["show subnet_mask"] = showSubnetMask;
    commandMap["show gateway"] = showGateway;
    commandMap["starwar"] = starwar;
    commandMap["show all_interfaces"] = showAllNetworkInterfaces;
    commandMap["show wireless_networks"] = showWirelessNetworkInfo;
	commandMap["clear"] = clear;
    commandMap["use shell"] = shell;
    
    
    while (true) {
	
    beg:
	cout << "[NETMAN]> ";
        getline(cin, input);
        if (input.empty())
		goto beg;
        
        if (input.find("ping") == 0) {
            string ip = input.substr(5);
            showPing(ip);
        } else if (input.find("trace") == 0) {
            string ip = input.substr(6);
            showTraceroute(ip);
        } else if (input == "help" || input == "options"|| input == "commaands"|| input == "show") {
            showHelp();
        } else if (input == "exit"|| input == "quit"|| input == "leave") {
            cout << "Exiting program.\n";
            break;
        } else if (commandMap.find(input) != commandMap.end()) {
            
            commandMap[input]();
        } else {
            cout << "Unknown command: " << input << "\n";
        }
    }

    return 0;
}
