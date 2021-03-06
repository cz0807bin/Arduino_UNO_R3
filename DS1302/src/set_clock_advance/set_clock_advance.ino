/*
Arduino 连接 DS1302
代码来源：http://quadpoint.org/projects/arduino-ds1302
增加了串口调整时间代码
*/
#include <stdio.h>
#include <string.h>
#include <DS1302.h>  /* DS1302 库 */

/* 接口定义
CE(DS1302 pin5) -> Arduino D5
IO(DS1302 pin6) -> Arduino D6
SCLK(DS1302 pin7) -> Arduino D7
*/
uint8_t CE_PIN   = 5;  /* RST引脚 */
uint8_t IO_PIN   = 6;  /* I/O引脚 */
uint8_t SCLK_PIN = 7;  /* SCLK引脚 */

/* 日期变量缓存 */
char buf[50];
char day[10];
/* 串口数据缓存 */
String comdata="" ;
int numdata[7] ={0}, mark = 0;
/* 创建 DS1302 对象 */
DS1302 rtc(CE_PIN, IO_PIN, SCLK_PIN);


/* 打印出 DS1302 当前时间 */
void print_time()
{
    /* 从 DS1302 获取当前时间 */
    Time t = rtc.time();
    /* 将星期从数字转换为名称 */
    memset(day, 0, sizeof(day));
    switch (t.day)
    {
        case 1:
            strcpy(day, "Sunday");
            break;
        case 2:
            strcpy(day, "Monday"); 
            break;
        case 3:
            strcpy(day, "Tuesday");
            break;
        case 4:
            strcpy(day, "Wednesday");
            break;
        case 5:
            strcpy(day, "Thursday");
            break;
        case 6:
            strcpy(day, "Friday");
            break;
        case 7:
            strcpy(day, "Saturday");
            break;
        default:
            break;
    }

    /* 将日期代码格式化凑成buf等待输出 */
    snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d", day, t.yr, t.mon, t.date, t.hr, t.min, t.sec);
    /* 输出日期到串口 */
    Serial.println(buf);
}


void setup()
{
    Serial.begin(9600);  /* 设置串口波特率9600 */
    rtc.write_protect(false);  /* 关闭写保护 */
    rtc.halt(false);
}


void loop()
{
    /* 当串口有数据的时候，将数据拼接到变量comdata */
    while(Serial.available() > 0)
    {
        comdata += char(Serial.read());
        delay(2);
        mark = 1;
    }
    /* 以逗号分隔分解comdata的字符串，分解结果变成转换成数字到numdata[]数组 */
    if(mark == 1)
    {
        Serial.print("You inputed : ");
        Serial.println(comdata);

        numdata[0] = (comdata[0]-'0') * 1000 + (comdata[1] - '0')+(comdata[2]-'0') * 100 + (comdata[3] - '0');//year
        numdata[1] = (comdata[4]-'0') * 10 + (comdata[5] - '0');//month
        numdata[2] = (comdata[6]-'0') * 10 + (comdata[7] - '0');//date
        numdata[3] = (comdata[8]-'0') * 10 + (comdata[9] - '0');//hour  
        numdata[4] = (comdata[10]-'0') * 10 + (comdata[11] - '0');//minute
        numdata[5] = (comdata[12]-'0') * 10 + (comdata[13] - '0');//second
        numdata[6] = (comdata[14]-'0') * 10 + (comdata[15] - '0');//week

        /* 将转换好的numdata凑成时间格式，写入 DS1302 */
        Time t(numdata[0], numdata[1], numdata[2], numdata[3], numdata[4], numdata[5], numdata[6]);
        rtc.time(t);
        mark = 0;
        /* 清空 comdata 变量，以便等待下一次输入 */
        comdata = String("");
        /* 清空 numdata */
        for(int i = 0; i < 7 ; i++) 
            numdata[i]=0;
    }
    
    /* 打印当前时间 */
    print_time();
    delay(1000);
}
