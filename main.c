#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// The USS Library
#include "include/uss.h"

/**
 * Test config
 */
#define CONFIG_TEST_PORT        10088
#define CONFIG_TEST_SERVER      "127.0.0.1"
#define CONFIG_TEST_LINK_MODE   USS_LINK_TYPE_SOFTWARE

/**************************************
 * Global test data
 **************************************/
struct running_stat
{
    unsigned long send, recv;
} run_stat;
static uss_instance_t uss;

/**************************************
 * Running thread
 **************************************/
static void *server_test_thread(void *arg)
{
    return NULL;
}

static void *client_test_thread(void *arg)
{
    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_port           = CONFIG_TEST_PORT;
    addr.sin_addr.s_addr    = inet_addr(CONFIG_TEST_SERVER);

    uss_connection_create(uss, (struct sockaddr*)&addr, CONFIG_TEST_LINK_MODE);
    return NULL;
}

static void show_statistic()
{
    uss_instance_t uss = uss_create();
    printf("Running stat:\n");
    printf("  send bytes %lu", run_stat.send);

    memset(&run_stat, 0, sizeof(run_stat));
}

int main() {
    pthread_t thread_srv, thread_cli;

    // Step1, the instance
    uss = uss_create();

    // Step2, the test thread to make offload
    printf("Hello, Let's create a server with USS.\n");
    pthread_create(&thread_srv, NULL, server_test_thread, NULL);
    pthread_create(&thread_cli, NULL, client_test_thread, NULL);

    // Statistic
    while (1) {
        sleep(1);
        show_statistic();
    }
    return 0;
}
