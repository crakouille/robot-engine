#include <RobotEngine/Utils/LinuxToArduino/LTACommunicationDriver.h>

#include <sys/select.h>		/* fd_set */
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>		/*open*/
#include <fcntl.h>		/*open*/
#include <signal.h>		/*kill*/
#include <unistd.h>		/*read, write, close, fork*/
#include <termios.h>		/*tcgetattr, cfsetospeed, cfsetispeed, tcsetattr, tcdrain struct termios*/
#include <iostream>		/*cerr, cout, endl*/
#include <cstring>		/*strerr*/
#include <cerrno>		/*errno*/
#include <ctime>		/*clock_gettime(implique -lrt), nanosleep*/

using namespace reu;
using namespace reu::lta;

LTACommunicationDriver::LTACommunicationDriver(const char *device, int speed)
{
  _device = open(device, O_RDWR | O_NOCTTY);// | O_NONBLOCK);

  if(_device < 0) {
    printf("Erreur: Périphérique %s non ouvert (sudo manquant ?).\n", device);
    return;
  }

  // Set terminal attributes
	struct termios options;

	tcgetattr(_device, &options);

  int bauds = B0;

  switch(speed) {
    case 0:
      bauds = B0;
      break;
    case 50:
      bauds = B50;
      break;
    case 75:
      bauds = B75;
      break;
    case 110:
      bauds = B110;
      break;
    case 134:
      bauds = B134;
      break;
    case 150:
      bauds = B150;
      break;
    case 200:
      bauds = B200;
      break;
    case 300:
      bauds = B300;
      break;
    case 600:
      bauds = B600;
      break;
    case 1200:
      bauds = B1200;
      break;
    case 1800:
      bauds = B1800;
      break;
    case 2400:
      bauds = B2400;
      break;
    case 4800:
      bauds = B4800;
      break;
    case 9600:
      bauds = B9600;
      break;
    case 19200:
      bauds = B19200;
      break;
    case 38400:
      bauds = B38400;
      break;
    case 57600:
      bauds = B57600;
      break;
    case 115200:
      bauds = B115200;
      break;
    case 230400:
      bauds = B230400;
      break;
    default:
      break;
  }

	// Bauds
	cfsetospeed(&options, bauds);
	cfsetispeed(&options, bauds);

  // Options extract from ssty on special device while the analog reader of the Arduino IDE is running

  options.c_cflag &= ~(PARENB | PARODD | HUPCL | CSTOPB | CRTSCTS);
	options.c_cflag |= ( CS8 | CREAD | CLOCAL );
	
	options.c_iflag &= ~(IGNBRK | BRKINT | IGNPAR | PARMRK | ISTRIP
			     | INLCR | IGNCR | ICRNL | IXON | IXOFF
			     | IUCLC | IXANY | IMAXBEL | IUTF8);
	options.c_iflag |= INPCK;
	
	options.c_oflag &= ~(OPOST | OLCUC | OCRNL | ONLCR | ONOCR
			     | ONLRET | OFILL | OFDEL);
	options.c_lflag &= ~(ECHO | ECHONL | ECHOE | ECHOK | ICANON
			     | ISIG | IEXTEN | NOFLSH | XCASE | TOSTOP
			     | ECHOPRT | ECHOCTL | ECHOKE);
	options.c_oflag |=(NL0 | CR0 | TAB0 | BS0 | VT0 | FF0 );

	tcsetattr(_device, TCSANOW, &options);
}

LTACommunicationDriver::~LTACommunicationDriver()
{
  close(_device);
}

re::Sint16 LTACommunicationDriver::read2(void *p, re::Uint16 maxsize)
{
  int i = 0, j;
  re::Uint8 *c = (re::Uint8 *) p;

  for(i = 0; i < maxsize; ) {
    j = ::read(_device, &c[i], maxsize - i);

    if(j > 0)
      i += j;
  }

  return i;
}

bool LTACommunicationDriver::send2(const void *p, re::Uint16 size)
{
  re::Uint16 size2;

  size2 = (re::Uint16) ::write(_device, p, size);
  
  return size == size2;
}

