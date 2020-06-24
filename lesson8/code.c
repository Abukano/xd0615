
const int ledPin =  LED_BUILTIN;// LED_BUILTIN是UNO内置定义的常量，为板载led连接的引脚编号
		                  //这里用LED_BUILTIN 13引脚控制发光二极管的正极

int ledState = LOW;             // 输出信号控制二极管的状态

unsigned long previousMillis = 0;        //用来记录二极管上一次闪烁的时间
// constants won't change :
const long interval = 1000;           // 常量，二极管闪烁的间隔（毫秒）

void setup() {
  pinMode(ledPin, OUTPUT);//将LED_BUILTIN对应的引脚13设为输出脚以控制
}

void loop() {
  // 利用previousMillis来记录闪烁的时间，当程序运行时间与闪烁时间相距interval时再次闪烁（关闭或开启）
  unsigned long currentMillis = millis();//millis()函数返回自Arduino开发板开始运行当前程序以来的毫秒数。大约50天后，该数字将溢出（返回零）。
  			            //currentMilis记录当前时间

  if (currentMillis - previousMillis >= interval) {
    // 如果当前时间距离上一次闪烁时间记录此次时间
    previousMillis = currentMillis;

    // 将LED状态设置为与上次相反
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // 设置LED为对应状态
    digitalWrite(ledPin, ledState);
  }
}