# 版本记录(Change Log)

## 0.1.2(2024-12-08)

* **NestApp**
  * 删除Application构造函数中初始化日志系统的代码
  * 实现Log类导出
  * 添加断言(Assert)
* **NestUI**
  * 解决DockWidgetManager中的单例指针未进行初始化检查的问题

## 0.1.1(2024-12-03)

* **NestUI**
  * 将基于SARibbonMainWindow的MainWindow设计成抽象类，并改名为NestMainWindow

## 0.1.0(2024-12-01)

* **NestApp**
  * 实现Application
  * 实现基于spdlog库的日志模块，包括控制台输出日志(Log to Console)和在QTextEdit中输入日志(Log to Qt)
* **NestUI**
  * 集成第三方UI库SARibbon
  * 实现基于SARibbonMainWindow的MainWindow
  * 实现基于QDockWidget的停靠窗口DockWidget
  * 实现停靠窗口管理器DockWidgetManager
