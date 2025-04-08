#include "net/mac/custom-mac.h"
#include "net/packetbuf.h"
#include "net/netstack.h"
#include "sys/ctimer.h"
#include <stdio.h>

static void init(void)
{
  printf("Custom MAC: Initialized\n");
}

static void send(mac_callback_t sent_callback, void *ptr)
{
  printf("Custom MAC: Sending packet\n");
  NETSTACK_RADIO.send(packetbuf_hdrptr(), packetbuf_totlen());
  if (sent_callback)
  {
    sent_callback(ptr, MAC_TX_OK, 1);
  }
}

static void input(void)
{
  printf("Custom MAC: Packet received\n");
  NETSTACK_NETWORK.input();
}

const struct mac_driver custom_mac_driver = {
    "CustomMAC",
    init,
    send,
    input};
