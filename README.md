# 遥感控制
一个由两个控制台程序组成的“双线程”软件；
分为人脸检测和运动球两部分；

## 人脸检测
用VS开发，基于OpenCV库；
从摄像头捕捉人脸的运动，将数据不断输出到交互文件。

## 运动球
用CB开发，基于OpenFrameWorks库；
不断从交互文件读入数据，并根据数据显示运动球。

***
> 编译环境：  
> Microsoft Visual Studio Professional 2013  
> 版本 12.0.31101.00 Update 4  
> Code::Blocks  
> 版本 13.12  
***
> 依赖库:  
> OpenCV 2.4.9 for Windows  
> OpenFrameWorks of_v0.8.2_win_cb_release  
