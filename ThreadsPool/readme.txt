 线程池和数据库连接池的原理

  本文我们简单介绍了一下数据库连接池和线程池的工作原理，希望能够对您有所帮助。

   当客户端请求的数据量比较大的时候，使用线程池可以节约大量的系统资源，使得更多的CPU时间和内存可以高效地利用起来。而数据库连接池的使用则将大大提高程序运行效率，同时，我们可以通过其自身的管理机制来监视数据库连接的数量、使用情况等。本文我们主要就介绍一下线程池和数据库连接池的原理，接下来我们一起来了解一下这一部分内容。

   线程池的原理：

   其实线程池的原理很简单，类似于操作系统中的缓冲区的概念，它的流程如下：先启动若干数量的线程，并让这些线程都处于睡眠状态，当客户端有一个新请求时，就会唤醒线程池中的某一个睡眠线程，让它来处理客户端的这个请求，当处理完这个请求后，线程又处于睡眠状态。可能你也许会问：为什么要搞得这么麻烦，如果每当客户端有新的请求时，我就创建一个新的线程不就完了？这也许是个不错的方法，因为它能使得你编写代码相对容易一些，但你却忽略了一个重要的问题?那就是性能！就拿我所在的单位来说，我的单位是一个省级数据大集中的银行网络中心，高峰期每秒的客户端请求并发数超过100，如果为每个客户端请求创建一个新线程的话，那耗费的CPU时间和内存将是惊人的，如果采用一个拥有200个线程的线程池，那将会节约大量的系统资源，使得更多的CPU时间和内存用来处理实际的商业应用，而不是频繁的线程创建与销毁。

   数据库连接池的原理：

   数据库连接是一种关键的有限的昂贵的资源，这一点在多用户的网页应用程序中体现得尤为突出。

   一个数据库连接对象均对应一个物理数据库连接，每次操作都打开一个物理连接，使用完都关闭连接，这样造成系统的性能低下。 数据库连接池的解决方案是在应用程序启动时建立足够的数据库连接，并讲这些连接组成一个连接池(简单说：在一个“池”里放了好多半成品的数据库联接对象)，由应用程序动态地对池中的连接进行申请、使用和释放。对于多于连接池中连接数的并发请求，应该在请求队列中排队等待。并且应用程序可以根据池中连接的使用率，动态增加或减少池中的连接数。

   连接池技术尽可能多地重用了消耗内存地资源，大大节省了内存，提高了服务器地服务效率，能够支持更多的客户服务。通过使用连接池，将大大提高程序运行效率，同时，我们可以通过其自身的管理机制来监视数据库连接的数量、使用情况等。

   1)最小连接数是连接池一直保持的数据库连接，所以如果应用程序对数据库连接的使用量不大，将会有大量的数据库连接资源被浪费；

   2)最大连接数是连接池能申请的最大连接数，如果数据库连接请求超过此数，后面的数据库连接请求将被加入到等待队列中，这会影响之后的数据库操作。

关于数据库连接池和线程池的原理的介绍就到这里了，希望本次的介绍能够带给您一些收获！



http://blog.csdn.net/hubi0952/article/details/7993811
1.分配式(每一个新连接分配一个线程，线程自己接受)
2.抢占式（主线程只接受，维护长连接，其他线程只处理，返回消息，返回后再放入消息队列）。


1）原理分析

线程池的核心设计思想是系统在初始化时，创建一定数量的服务线程，并使他们处于空闲状态，若当前有新用户到来，则系统先查找当前有无空闲线程，若有则立即为其分配服务线程，如没有，则将新用户加入待服务队列，并在其他用户结束服务时，再重新为其分配服务线程。

新用户如果在等待服务队列里的时间过长，会影响用户体验。

方法：1、动态创建新服务线程，服务结束后，该线程加入到线性池，但大量的用户下，使线程池变得很大，最后因资源消耗过多。2、在1的基础上增加线程资源回收机制。当线程规模达到一定程度，会主动杀死一些进程。


该系统简单的设计方案：

1、系统在初始化时，开辟MAX_NUM个线程（MAX_NUM是个宏，默认20）组成服务线程池

2、每个线程均分为有两个状态，一个是空闲状态，另一个是工作状态，每个线程均有一块属于自己的公共数据区域，这块数据区域中存放两个变量，其中一个变量标记自身状态，0则表示处于空闲状态；1则为工作状态。另一个变量对应客户端的套接字号，如果线程处于空闲状态，则套接字号为0；

3、有新用户到来时，系统通过查找公共数据区域，判断当前是否有空闲线程，若有则直接为其分配服务线程。

4、若当前没有空闲程序，系统将不做任何处理，提示当前系统忙，关闭新客户套接字。
