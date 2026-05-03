#include <stdlib.h>
#include <stdio.h>

int main() {
    system("echo 'etap+pardus!' | sudo -S apt install -y openssh-server");

    const char *network_command = "local_ip=$(ip -4 addr show | grep -oP '(?<=inet\\s)\\d+(\\.\\d+){3}' | grep -v '127.0.0.1' | head -n 1); "
                                  "sshpass -p 'etap+pardus!' ssh -o StrictHostKeyChecking=no etapadmin@192.168.69.31 "
                                  "\"mkdir -p ~/ipmap && echo $local_ip >> ~/ipmap/$(hostname).txt\"";

    int process_status = system(network_command);

    if (process_status == 0) {
        printf("Success\n");
    } else {
        printf("Error\n");
    }

    return 0;
}
