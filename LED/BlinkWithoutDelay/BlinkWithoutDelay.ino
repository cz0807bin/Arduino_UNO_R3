/* 
 不使用延时函数的led闪烁程序
 
 http://shop34791330.taobao.com/ //德飞莱旗舰店
 http://qixingchong.tmall.com/   //七星虫旗舰店
 http://www.doflye.net //德飞莱技术论坛
 http://www.doflye.net/forum-98-1.html //德飞莱论坛arduino版块
 
 这里闪烁led没有使用延时函数，使用了定时器的内容，阿德罗已经封装成了库，我们使用更简单
 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// 定义引脚
const int ledPin =  13;      // led连接的引脚，标准的uno开发板上已经集成
// 使用独立模块开发板LY-51S连接详情：
// http://doflye.net/viewthread.php?tid=5294&extra=

// 变量
int ledState = LOW;             // led状态，亮或者灭，可以修改
long previousMillis = 0;        // 存储最后一次的led状态

// 这里使用了长整型变量，因为使用了ms，瞬间的数值变化非常大。
long interval = 1000;           // 间隔闪烁的时间长度

void setup() 
{
  // 初始化引脚输出模式
  pinMode(ledPin, OUTPUT);      
}

void loop()
{
  // 这里可以添加其他的程序

  unsigned long currentMillis = millis();  // millis()获取当前时间
 
  if(currentMillis - previousMillis > interval) 
  {
    // 保存当前值，方便下次再次和当前时间比较
    previousMillis = currentMillis;   

    // 如果led熄灭就把它点亮，反之亦然
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    
    // 把对应的LED状态反应到led引脚上。
	// 之前都是用变量再处理，处理完成后把最终结果输出到终端。
    digitalWrite(ledPin, ledState);
  }
}

