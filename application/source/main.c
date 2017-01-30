#include <string.h>

#include <time.h>
#include <stdlib.h>

#include <stdio.h>

#include <sys/stat.h>
#include <unistd.h>
#include <3ds.h>
#include <time.h>


const char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

const char* weekDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


const u16 daysAtStartOfMonthLUT[12] =
{
    0	%7, //januari		31
    31	%7, //februari		28+1(leap year)
    59	%7, //maart			31
    90	%7, //april			30
    120	%7, //mei			31
    151	%7, //juni			30
    181	%7, //juli			31
    212	%7, //augustus		31
    243	%7, //september		30
    273	%7, //oktober		31
    304	%7, //november		30
    334	%7  //december		31
};

#define isLeapYear(year) (((year)%4) == 0)

uint getDayOfWeek(uint day, uint month, uint year)
{
    //http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week
    
    day += 2*(3-((year/100)%4));
    year %= 100;
    day += year + (year/4);
    day += daysAtStartOfMonthLUT[month] - (isLeapYear(year) && (month <= 1));
    return day % 7;
}





int main(int argc, char **argv) {

	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	printf("Hello 3DS World!\n");
    
    

    bool cartCheck()
    {
        //Check if there is a cart
        bool cartInserted;
        FSUSER_CardSlotIsInserted(&cartInserted);
        if(!cartInserted)
        {
            printf("No cartridge inserted!\n");
            return 0;
        }
        
        //Make sure it's a 3ds game
        FS_CardType type;
        FSUSER_GetCardType(&type);
        if(type!=CARD_CTR)
        {
            printf("No DS support.\n");
            return 2;
        }
        return 1;
    }
    
    int isCartIn=cartCheck();
    
    
    printf("Roses are \x1b[31mred\x1b[0m\n");
    printf("Violets are \x1b[34mblue\x1b[0m\n");
    printf("Piracy is bad\n");
    printf("While homebrews are good\n\n");
    
    
    
    void colorTest()
    {
        int n;
        n = rand() % 7 + 1;
        if (n==0) {
            printf("\x1b[30mlolololololololololololololololololololololololol\x1b[0m\n");
            printf("\x1b[30mlolololololololololololololololololololololololol\x1b[0m\n");
            printf("\x1b[30mlolololololololololololololololololololololololol\x1b[0m\n");
            printf("\x1b[30mlolololololololololololololololololololololololol\x1b[0m\n");
            printf("\x1b[30mlolololololololololololololololololololololololol\x1b[0m\n");
            printf("\x1b[30;1mlolololololololololololololololololololololololol\x1b[0m\n");
            printf("\x1b[30;1mlolololololololololololololololololololololololol\x1b[0m\n");
            printf("\x1b[30;1mlolololololololololololololololololololololololol\x1b[0m\n");
            printf("\x1b[30;1mlolololololololololololololololololololololololol\x1b[0m\n");
            printf("\x1b[30;1mlolololololololololololololololololololololololol\x1b[0m\n");
        }
        else{
            if (n==1) {
                printf("\x1b[31mlolololololololololololololololololololololololol\x1b[0m\n");
                printf("\x1b[31mlolololololololololololololololololololololololol\x1b[0m\n");
                printf("\x1b[31mlolololololololololololololololololololololololol\x1b[0m\n");
                printf("\x1b[31mlolololololololololololololololololololololololol\x1b[0m\n");
                printf("\x1b[31mlolololololololololololololololololololololololol\x1b[0m\n");
                printf("\x1b[31;1mlolololololololololololololololololololololololol\x1b[0m\n");
                printf("\x1b[31;1mlolololololololololololololololololololololololol\x1b[0m\n");
                printf("\x1b[31;1mlolololololololololololololololololololololololol\x1b[0m\n");
                printf("\x1b[31;1mlolololololololololololololololololololololololol\x1b[0m\n");
                printf("\x1b[31;1mlolololololololololololololololololololololololol\x1b[0m\n");
            }
            else{
                if (n==2) {
                    printf("\x1b[32mlolololololololololololololololololololololololol\x1b[0m\n");
                    printf("\x1b[32mlolololololololololololololololololololololololol\x1b[0m\n");
                    printf("\x1b[32mlolololololololololololololololololololololololol\x1b[0m\n");
                    printf("\x1b[32mlolololololololololololololololololololololololol\x1b[0m\n");
                    printf("\x1b[32mlolololololololololololololololololololololololol\x1b[0m\n");
                    printf("\x1b[32;1mlolololololololololololololololololololololololol\x1b[0m\n");
                    printf("\x1b[32;1mlolololololololololololololololololololololololol\x1b[0m\n");
                    printf("\x1b[32;1mlolololololololololololololololololololololololol\x1b[0m\n");
                    printf("\x1b[32;1mlolololololololololololololololololololololololol\x1b[0m\n");
                    printf("\x1b[32;1mlolololololololololololololololololololololololol\x1b[0m\n");
                }
                else{
                    if (n==3) {
                        printf("\x1b[33mlolololololololololololololololololololololololol\x1b[0m\n");
                        printf("\x1b[33mlolololololololololololololololololololololololol\x1b[0m\n");
                        printf("\x1b[33mlolololololololololololololololololololololololol\x1b[0m\n");
                        printf("\x1b[33mlolololololololololololololololololololololololol\x1b[0m\n");
                        printf("\x1b[33mlolololololololololololololololololololololololol\x1b[0m\n");
                        printf("\x1b[33;1mlolololololololololololololololololololololololol\x1b[0m\n");
                        printf("\x1b[33;1mlolololololololololololololololololololololololol\x1b[0m\n");
                        printf("\x1b[33;1mlolololololololololololololololololololololololol\x1b[0m\n");
                        printf("\x1b[33;1mlolololololololololololololololololololololololol\x1b[0m\n");
                        printf("\x1b[33;1mlolololololololololololololololololololololololol\x1b[0m\n");
                    }
                    else{
                        if (n==4) {
                            printf("\x1b[34mlolololololololololololololololololololololololol\x1b[0m\n");
                            printf("\x1b[34mlolololololololololololololololololololololololol\x1b[0m\n");
                            printf("\x1b[34mlolololololololololololololololololololololololol\x1b[0m\n");
                            printf("\x1b[34mlolololololololololololololololololololololololol\x1b[0m\n");
                            printf("\x1b[34mlolololololololololololololololololololololololol\x1b[0m\n");
                            printf("\x1b[34;1mlolololololololololololololololololololololololol\x1b[0m\n");
                            printf("\x1b[34;1mlolololololololololololololololololololololololol\x1b[0m\n");
                            printf("\x1b[34;1mlolololololololololololololololololololololololol\x1b[0m\n");
                            printf("\x1b[34;1mlolololololololololololololololololololololololol\x1b[0m\n");
                            printf("\x1b[34;1mlolololololololololololololololololololololololol\x1b[0m\n");
                        }
                        else{
                            if (n==5) {
                                printf("\x1b[35mlolololololololololololololololololololololololol\x1b[0m\n");
                                printf("\x1b[35mlolololololololololololololololololololololololol\x1b[0m\n");
                                printf("\x1b[35mlolololololololololololololololololololololololol\x1b[0m\n");
                                printf("\x1b[35mlolololololololololololololololololololololololol\x1b[0m\n");
                                printf("\x1b[35mlolololololololololololololololololololololololol\x1b[0m\n");
                                printf("\x1b[35;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                printf("\x1b[35;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                printf("\x1b[35;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                printf("\x1b[35;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                printf("\x1b[35;1mlolololololololololololololololololololololololol\x1b[0m\n");
                            }
                            else{
                                if (n==6) {
                                    printf("\x1b[36mlolololololololololololololololololololololololol\x1b[0m\n");
                                    printf("\x1b[36mlolololololololololololololololololololololololol\x1b[0m\n");
                                    printf("\x1b[36mlolololololololololololololololololololololololol\x1b[0m\n");
                                    printf("\x1b[36mlolololololololololololololololololololololololol\x1b[0m\n");
                                    printf("\x1b[36mlolololololololololololololololololololololololol\x1b[0m\n");
                                    printf("\x1b[36;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                    printf("\x1b[36;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                    printf("\x1b[36;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                    printf("\x1b[36;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                    printf("\x1b[36;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                }
                                else{
                                    if (n==7) {
                                        printf("\x1b[37mlolololololololololololololololololololololololol\x1b[0m\n");
                                        printf("\x1b[37mlolololololololololololololololololololololololol\x1b[0m\n");
                                        printf("\x1b[37mlolololololololololololololololololololololololol\x1b[0m\n");
                                        printf("\x1b[37mlolololololololololololololololololololololololol\x1b[0m\n");
                                        printf("\x1b[37mlolololololololololololololololololololololololol\x1b[0m\n");
                                        printf("\x1b[37;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                        printf("\x1b[37;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                        printf("\x1b[37;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                        printf("\x1b[37;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                        printf("\x1b[37;1mlolololololololololololololololololololololololol\x1b[0m\n");
                                    }
                                    else
                                    {
                                        printf("No\x1b[0m\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
//    colorTest();
//    colorTest();
//    colorTest();
//    colorTest();
//    colorTest();
//    colorTest();
//    colorTest();
    colorTest();
    //bool isCartIn=cartCheck();
    if(isCartIn==0)
    {
        printf("No Cartridge\n");
    }
    else
    {
        if (isCartIn==1) {
            printf("3DS Cartridge\n");
        }
        else
        {
            printf("DS Cartridge\n");
        }
        
    }
    
    u8 language = 0;
    Result langRes;
    langRes = CFGU_GetSystemLanguage(&language);
    printf("       Result: 0x%x\n", (int)langRes);
    printf("Language code: %d", (int)language);
    
    u8 model = 0;
    Result modelRes;
    modelRes = CFGU_GetSystemModel(&model);
    printf("       Result: 0x%x\n", (int)modelRes);
    printf("Model code: %d", (int)model);
    
    u8 region = 0;
    Result regionRes;
    regionRes = CFGU_SecureInfoGetRegion(&region);
    printf("       Result: 0x%x\n", (int)regionRes);
    printf("Model code: %d", (int)region);
    
    if (region==1) {
        u8 usa = 0;
        Result usaRes;
        usaRes = CFGU_GetRegionCanadaUSA(&usa);
        printf("       Result: 0x%x\n", (int)usaRes);
        printf("Model code: %d", (int)usa);
    }
    
    OS_VersionBin nver, cver;
    osGetSystemVersionData(&nver, &cver);
    
    printf("SYSTEM version %d.%d.0-%d\n", cver.mainver, cver.minor, nver.mainver);
    
    
    
	// Main loop
	while (aptMainLoop()) {

		gspWaitForVBlank();
		hidScanInput();
        
        

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

        
//        time_t unixTime = time(NULL);
//        struct tm* timeStruct = gmtime((const time_t *)&unixTime);
//        
//        int hours = timeStruct->tm_hour;
//        int minutes = timeStruct->tm_min;
//        int seconds = timeStruct->tm_sec;
//        int day = timeStruct->tm_mday;
//        int month = timeStruct->tm_mon;
//        int year = timeStruct->tm_year +1900;
//        
//        printf("\x1b[0;0H%02i:%02i:%02i", hours, minutes, seconds);
//        printf("\n%s %s %i %i", weekDays[getDayOfWeek(day, month, year)], months[month], day, year);
        
        
        
        //colorTest();
        
        if (kDown & KEY_A) {
            printf("A\n");
        }
        if (kDown & KEY_B) {
            printf("B\n");
        }
        if (kDown & KEY_SELECT) {
            printf("Select\n");
        }
        if (kDown & KEY_DRIGHT) {
            printf("D-Pad Right\n");
        }
        if (kDown & KEY_DLEFT) {
            printf("D-Pad Left\n");
        }
        if (kDown & KEY_DUP) {
            printf("D-Pad Up\n");
        }
        if (kDown & KEY_DDOWN) {
            printf("D-Pad Down\n");
        }
        if (kDown & KEY_R) {
            printf("R\n");
        }
        if (kDown & KEY_L) {
            printf("L\n");
        }
        if (kDown & KEY_X) {
            printf("X\n");
        }
        if (kDown & KEY_Y) {
            printf("Y\n");
        }
        if (kDown & KEY_ZL) {
            printf("ZL\n");
        }
        if (kDown & KEY_ZR) {
            printf("ZR\n");
        }
        if (kDown & KEY_TOUCH) {
            printf("Touch Screen\n");
        }
        if (kDown & KEY_CSTICK_RIGHT) {
            printf("C-Stick Right\n");
        }
        if (kDown & KEY_CSTICK_LEFT) {
            printf("C-Stick Left\n");
        }
        if (kDown & KEY_CSTICK_UP) {
            printf("C-Stick Up\n");
        }
        if (kDown & KEY_CSTICK_DOWN) {
            printf("C-Stick Down\n");
        }
        if (kDown & KEY_CPAD_RIGHT) {
            printf("Circle Pad Right\n");
        }
        if (kDown & KEY_CPAD_LEFT) {
            printf("Circle Pad Left\n");
        }
        if (kDown & KEY_CPAD_UP) {
            printf("Circle Pad Up\n");
        }
        if (kDown & KEY_CPAD_DOWN) {
            printf("Circle Pad Down\n");
        }
        
        
        
		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}

	gfxExit();
	return 0;
}
