#include "wtap_pkthdr.h"
#include <string.h>
//void wtap_phdr_init(wtap_pkthdr *phdr)
//{
//    memset(phdr, 0, sizeof(struct wtap_pkthdr));
////    ws_buffer_init(&phdr->ft_specific_data, 0);
//}


void wtap_phdr_cleanup(wtap_pkthdr *phdr)
{

}

wtap_pkthdr::wtap_pkthdr()
{

}

wtap_pkthdr::~wtap_pkthdr()
{

}

void wtap_pkthdr::wtap_phdr_init()
{
    ft_specific_data.ws_buffer_init(0);
}
