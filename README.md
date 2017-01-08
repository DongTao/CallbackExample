# CallbackExample
本项目展示常见的回调对象方案实现与使用方法

##项目说明
示例场景展示Picture类利用Graphics类的异步接口完成自己的drawLollipop方法，注意Graphics类提供了3个异步接口并通过2个回调函数返回结果，而Picture类只用到其中2个接口和1个回调函数

###C/C++部分
1. boostbindfunc: 使用boost::bind和boost::function实现
2. fastdelegate: 使用Don Clugston的FastDelegate实现，与boostbindfunc方案非常相似
3. virtualcallback: 使用虚回调函数实现，使用者需要实现自己的回调类以实现绑定
4. cstyle: 使用C风格API，回调函数回传上下文，在用户侧映射到对象上

###测试环境
Ubuntu 14.04.1 LTS x86_64

###参考资料
[以boost::function和boost:bind取代虚函数](http://blog.csdn.net/Solstice/article/details/3066268)

[function/bind的救赎（上）](http://blog.csdn.net/myan/article/details/5928531)
