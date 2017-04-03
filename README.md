[![Project Status: Inactive – The project has reached a stable, usable state but is no longer being actively developed; support/maintenance will be provided as time allows.](http://www.repostatus.org/badges/latest/inactive.svg)](http://www.repostatus.org/#inactive)

# 概述

本程序是AB相编码器的驱动程序，可以用于对编码器的测试。通过Arduino串口监视器，我们可以与该程序进行交互，输入相应的命令，即可以获取到相应的数据。

本程序已在下述硬件环境进行测试：

- AB相磁编码器2个
- 直流减速电动机2个(12V, 366rpm)
- Arduino Mega 2560

其他硬件可能需要做相应的更改，不过改动应该很小。

# 引脚连接

| encoders | Arduino  |
| :------------- | :------------- |
| 左A相 | D2 |
| 左B相 | D22 |
| 右A相 | D3 |
| 右B相 | D24 |
| 左+5V  | +5V |
| 左GND | GND |
| 右+5V  | +5V |
| 右GND | GND |  

下图为具体的连接方法（以左前轮为例）：

![encoder](https://github.com/Saturn-robot/Encoder_driver/blob/master/Test_Encoders/circuit_diagram/FIT0403_encoder.png)

1、2接电源的正负极;

3接GND管脚，4接5V管脚;

5接中断管脚，6接普通的数字管脚;

注意：5,6引脚需要特别说明：我们所使用的Arduino Mega2560有6个中断管脚，如下表所示：


| 型号 | #0中断 | #1中断 | #2中断 | #3中断 | #4中断 | #5中断 |    
| :-------------: | :-------------: | :-------------: | :-------------: |  :-------------: | :-------------: |  :-------------: |
| Mega 2560 | 2 | 3 | 21 |  20 | 19 | 18 |    

不同的Arduino的中断管脚是不同的，详细内容请参考：<https://www.arduino.cc/en/Reference/AttachInterrupt>

# 运行

将该程序上传到arduino板中即可运行。

## 获取编码器数据

使用`e`命令即可获取到两个编码器的数据:

    e

## 编码器清零

使用`r`命令即可使编码器数据清零。

具体可以查看程序中的`command.h`文件:

```
#define READ_ENCODERS  'e'
#define RESET_ENCODERS 'r'
```

# 注意事项

- 安装增量式磁编码器时，要注意磁鼓不要接触到霍尔元件；
- 安装编码盘时，要注意导线的方向。安装之前最好做一个大致的布局，否则焊好之后很难改变导线的朝向；
