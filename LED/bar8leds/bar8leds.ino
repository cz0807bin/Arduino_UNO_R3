/*
 http://shop34791330.taobao.com/ //德飞莱旗舰店
 http://qixingchong.tmall.com/   //七星虫旗舰店
 http://www.doflye.net //德飞莱技术论坛
 http://www.doflye.net/forum-98-1.html //德飞莱论坛arduino版块

 简易流水灯
 
 使用独立模块开发板LY-51S连接详情：
 http://doflye.net/viewthread.php?tid=5294&extra=
 
 */


// 引脚定义
const int ledCount = 8;    // led个数

int ledPins[] = { 0, 1, 2, 3, 4, 5, 6, 7, };   // 对应的led引脚


void setup() 
{
  // 循环设置，把对应的led都设置成输出
  for (int thisLed = 0; thisLed < ledCount; thisLed++) 
  {
    pinMode(ledPins[thisLed], OUTPUT); 
  }
}

void loop() 
{
  // 熄灭所有led，不同的电路连接也会得到点亮所有led
    for (int num = 0; num < 8; num++) 
    {
      digitalWrite(ledPins[num], HIGH);
    } //
  // 循环顺序点亮led然后等待200ms后熄灭
  for (int num = 0; num < 8; num++) 
  {
      digitalWrite(ledPins[num], LOW);
      delay(200);
      digitalWrite(ledPins[num], HIGH);
  // 这样就形成了简易的led流水效果  
    } 
 }




