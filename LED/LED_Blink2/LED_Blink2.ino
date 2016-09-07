/*
 http://shop34791330.taobao.com/ //德飞莱旗舰店
 http://qixingchong.tmall.com/   //七星虫旗舰店
 http://www.doflye.net //德飞莱技术论坛
 http://www.doflye.net/forum-98-1.html //德飞莱论坛arduino版块
  led 以200ms频率闪烁2次 ，灭1秒，依此循环
 */
 
// led 连接到 13引脚
// 引脚定义:
int led = 13;

// 复位后初始化内容
void setup() 
{                
  // 初始化数字端口为输出模式
  pinMode(led, OUTPUT);     
}
// 使用独立模块开发板LY-51S连接详情：
// http://doflye.net/viewthread.php?tid=5294&extra=
// 主循环
void loop() 
{
  digitalWrite(led, HIGH);   // led引脚置高电平
  delay(100);               // 延时100ms
  digitalWrite(led, LOW);    // led引脚变为低电平
  delay(100);               // 延时100ms
   digitalWrite(led, HIGH);   // led引脚置高电平
  delay(100);               // 延时100ms
  digitalWrite(led, LOW);    // led引脚变为低电平
  delay(1000);               // 延时100ms
  
}
