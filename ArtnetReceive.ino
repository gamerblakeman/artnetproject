
#include <Conceptinetics.h>
#include <Artnet.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>

Artnet artnet;

// Change ip and mac address for your setup
byte ip[] = {192, 168, 0, 246};
byte broadcast[] = {192, 168, 0, 255};
byte mac[] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC};

void setup()
{
  artnet.begin(mac, ip);
  artnet.setBroadcast(broadcast);
}

void loop()
{
  uint16_t r = artnet.read();
  if(r == ART_POLL)
  {
  }
  if (r == ART_DMX)
  {
    for (int i = 0 ; i < artnet.getLength() ; i++)
    {
      dmx_master.setChannelValue(i, artnet.getDmxFrame()[i]);
    }
  }
}
