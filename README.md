[operating system organization.md](https://github.com/user-attachments/files/16932736/operating.system.organization.md)[Uploading operating syste# operating system organization

## isolation

操作系统内核完成不同进程在CPU上切换

操作系统向应用程序提供进程，进程抽象了CPU，所以操作系统能在多个程序间复用一个或多个CPU

操作系统内核要有防御性

user/kcrnel mode

privileged instructions中断系统调用unpriviloged CPu有标志位，标志是user or kerd mode Page table virtualaddr→Physicul addr pro coss has oun page table 每个进程只能访问出现在自己负表中的内存

user mode

![img](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/b78307d1070171ff)

kernel mode

应用程序调周用ecallc）＋Syscall asor kernel

用户的应用程执行系统调用的唯一方法是ecally 应用程序表现恶意或出现死循环，内核如何夺回控制収内核通过硬件设置一个定时器，到期后，控制权限从用户空间转到内核模式 ,xvb 宏内核 所有操作系统服务都在

操作系统内核 虫内核

微内核内核的部分其他进程作为用户程序运行

Page table (virtual memory)→isolation

/.Adress spase 2.paging hw (RISc-V)

3．Xv6 Virtyal memory＋（ayout（布向）

每个进程拥有自己的地址空间

![img](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/f852906334d13d4e)

lat sh 0

![img](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/5eaa9afe396de931)

![img](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/e8d0870d65401a2d)

CPV执行指令

Virtud address Physical atdress

mmv memory

![img](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/bf2b838b9427f31a)

保存将虚拟地址 mapping between 转成物理地址的表草 virtual andphysird 的地址

![img](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/32f1144a34cb10be)

virtual memory benefits

1．Isolation vn使oS可以为每个应用程序提供属于自己的地址空间vm提供了用户地址空间和内核地址空间的隔离性

1. level of indirection 处理器指令只能使用虚拟地址，而内核会定义从虚拟地址到物理地址的映射关系trampolne pagc 允许内核将一个page映射到多个地址空间

如何在一物理内存上创建不同的地址空间使用页表

CPu告诉mmu从哪里找到将虚拟内存地址翻译为物理内存地址的表单Muu不存储映射，只是从内有读取内容并转换

Virtual address SV39只有低于39位使用

inderx 用来查找Page227个PTE offset 对应的是page中的哪个书Per page→4KB 连续在物理内存

![img](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/f326a24a7f5fd6ad)

页表在物理内存的实际存在形式是

3级树

12

Offset

Vm

前9bit用来引最高级的Page directory

![img](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/01f2e747f77655d5)

PTE：Page table Entry 页表入D

| PTE R | eserved Ph | ysical Page N | umberRSWD |
| ----- | ---------- | ------------- | --------- |
|       |            |               |           |

![img](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/39f83bdc5a2786d2)

Translation lock-aside buffer（TLB）页表缓存是PTE的缓存

如果切换了Page table，操作系统会告知处理器当前正在切换page table，处理器会青空TLB

高于0x8000的地址走向Dram低于的走向硬件

DRAM

| Virtual Addresses | 56-1R-X-RW-RWRW- | Unused                      |
| ----------------- | ---------------- | --------------------------- |
| Trampoline        | 56-1R-X-RW-RWRW- | Unused                      |
| Guard page        | 56-1R-X-RW-RWRW- | Unused                      |
| Kstack 0          | 56-1R-X-RW-RWRW- | Unused                      |
| Guard page        | 56-1R-X-RW-RWRW- | Unused                      |
| Kstack 1          | 56-1R-X-RW-RWRW- | Unused                      |
| …                 | 56-1R-X-RW-RWRW- | Unused                      |
| Free memory       | 56-1R-X-RW-RWRW- | Physical memory (RAM)       |
| Kernel data       | RW-恒等R-X 映射  | Physical memory (RAM)       |
| Kernel text       | RW-恒等R-X 映射  | Physical memory (RAM)       |
|                   | RW-              | Unusedand other I/O devices |
| VIRTIO diskUARTO  | RW-              | VIRTIO disk                 |
|                   | RWRW-            | UARTO                       |
|                   | RWRW-            |                             |
| PLIC              | RWRW-            | PLIC                        |
|                   | 0x020000000x1000 |                             |
|                   | 0x020000000x1000 | CLINT                       |
|                   | 0x020000000x1000 | Unused                      |
|                   | 0x020000000x1000 | boot ROM                    |
|                   | 0x020000000x1000 | Unused                      |

I/O.deviles

页表是操作系统为每个进程提供自己的私有地址空间和内存的机制RISC-V的指令操作虚拟地址，机器内存用物理地址索引，RISC-V页表硬件将虚拟地址映射为物理地址

XV6使用Kalloc为进程提供更多的用户内存内核有单独的负表，

XV6只能分配一个大小固定的4096byte的页面

Reduced Instruction Set Computer

Stuck是从高地址开始向低地比使用栈向下增长





# Trap and system calls

**3种情况会使CPU搁置普通指令执行**

1. 系统调用  使用ecall来让内核做事
2. 异常 指令非法执行
3. 中断 设备发出中断信号

**在XV6中处理trap过程分为四个阶段**

1. **RISC-V CPU的硬件操作**

   保存当前程序的执行状态（如PC和register的值）确定引发trap的原因（如：系统调用、异常或是设备中断）跳转到一个预定义的内存位置

2. **汇编向量准备**

   保存更多的处理器状态，比如所有寄存器的值，以确保不会丢任何重要信息。

   切换到内核模式，使用内核的栈空间

   准备好调用C语言写的trap处理程序

3. **C语言trap处理程序**

   根据trap的类型和原因决定如何处理当前trap

   如果是系统调用，就处理系统调用，如果是设备中断就调用相应的设备驱动程序，如果是其他异常，就采取其他措施，终止错误进程

4. **系统调用或驱动服务例程**

   执行实际的系统调用或设备驱动服务例程

   调用设备驱动程序处理来白硬件的中断

**为什么需要不同的汇编向量和C语言trap处理程序？**

虽然所有trap处理流程看起来相似，但在实际实现中，为了简化处理和提高效率，xv6为不同类型trap使用不同汇编向量和语言trap处理程序，好处是可以根据具体的trap类型执行特定的初步操作，减少不必要的检查处理

**当RISC-V触发个trap时（除计时器中断）它会做下列事**

1. 如果trap是设备中断，并且sstatus寄存器中的SIE位被清除，那么什么都不做
2. 通过清除SIE来禁用中断
3. 将PC的值复制到spec寄在器
4. 将当前模式信息（user／supevisor）保存到sstatus寄存器的SPP位
5. 设置Scause寄存器，记录trap原因
6. 将模式设置为supervisor
7. 将stvec寄存器的值复制到PC
8. 开始在新pc地址处执行

trap之前保存32个用户寄存器、PC、然后mode切换为 supervisor mod、SATP寄存器指向user Page toble

**以write()和exec()为例的trap过程**

![img](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/beeef055dce5d116)

![257466F6B1B85EF6C8FA6081648C30DA](C:\Users\r'j'j\Documents\Tencent Files\2365751550\FileRecv\MobileFile\257466F6B1B85EF6C8FA6081648C30DA.png)

trap，开始 中断或异常当内核代码执行中发生

从堆栈中弹出保有的寄


![](https://textin-image-store-1303028177.cos.ap-shanghai.myqcloud.com/external/c36dc1891c9bee7c)

## page-fault exceptions

在XV6中，如果异常发生在用户空间，内核会杀死出错的进程，如果发生在内核空间，内核会Panic

**写时复制**：

**问题：**当一个父进程创建子进程时，因为要复制父进程的内存内容所以会浪费大量内存，直接共享又会导致父子进程操作干扰。

**写时复制的思路：**父子进程共享同一块内存，但这块内存是只读的。如果父或子进程需要修改内存，CPU会检测到请求，并触发pagefault。系统捕捉到页面错误，复制该内存页，将它们分别设置为父进程和子进程可读写内存，这样只有在需要修改时复制，节省内存。

**lazy allocation**：

当程序请求更多内存时，内核会增加地址空间，但在页面表中将新地址标为无效，当触发面错误时，系统才分配实际的物理内存。

**从磁盘分页（paging from Disk）：**

有时程序需要的内存比可用物理RAM还多

系统将不常用的内有页面写到磁盘上，并将其PTE标记为无效，当程序要访问这些页面时，会触发页面错误，系统会将这些页面从磁盘读回内存，然后继续执行程序，这样系统可以在物理内存不足时，利用磁盘扩展内存空间。

**memory-mapped- files：**

将完整或部分文件加载到内存中，这样就可以通过使用load store 指令来操作文件的内容

**补充内容：**

1. ecall 将代码从usermode转到supervisormde，ecall将PC的值保存

2. 在SEPC寄存器，ecall会跳转到STVEC寄存器指向的指令

3. trampdine在用户空间和内核空间都映射到同一地址

4. trapframe 用于保存处理器。在发生trap时的状态，它保存了各部寄存器和状态信息，以便OS能正确处理中断和异常并在处理完后恢复程序的执行状态

5. sbrk（）xv6的system call 可使用户应用程序扩大自己的heap


![D2D2C1E5DC19930F3A7D25FE68EF47F7](C:\Users\r'j'j\Documents\Tencent Files\2365751550\FileRecv\MobileFile\D2D2C1E5DC19930F3A7D25FE68EF47F7.png)



# Interrupts and device drivers

## 什么是驱动程序？

驱动程序是操作系统中管理特定设备（鼠标、键盘、打印机）的代码，它能配置设备硬件、指示设备执行操作、处理中断、与进程交互（让需要设备进行输入输出的程序能顺利运行）

## 什么是中断？

当设备需要操作系统关注时，它会产生中断信号，内核trap处理代码收到中断信号后会调用驱动程序的中断处理部分来处理中断

**驱动程序分为2部分：**

上半部分：在程序需要设备执行任务时运行，比如读取设备、打印文档，这部分会告诉设备开始工作，然后等待设备完成任务。

下半部分：当设备完成任务发送中断信号时运行。这部分代码会处理中断信号，通知等待的程序，并告诉设备开始下一个任务。

**驱动的上下两部分可以并行运行**

**中断发生时：**

| 硬件                    | 软件                               |
| ----------------------- | ---------------------------------- |
| 现在需要操作系统关注 。 | 保存当前工作，处理中断，继续工作。 |

## system call和interrupt在软件层面的处理机制有什么区别和相似之处？

| 相同之处                                               | 不同之处                                                     |
| ------------------------------------------------------ | ------------------------------------------------------------ |
| 都使用了类似于保存当前工作，处理事件，继续工作这种机制 | 1．**中断是异步的**，这意味着当硬件生成中断，interrupt handler开始台运行，这个hander 与当前运行的进程在CPU上没有任何关联，因为中断是独立于当前任务的，中断可以在任何时候发生，不论当前处理器在执行什么任务。处理器不需要主动等待中断，而是继续执行其他任务。2．**并发性** 对于中断来说，CPU和生成中断的设备是并行运行的 |

## RISC-V support for interrupts

**部分用于interupts的寄存器**

SIE（Super visor Intermupt Enable）寄存器 

1. SIE_E.针对UART的外部设备中断
2. SIE_S：软件中断
3. SIE_T：定时器中断

SSTATUS（supewisor status）寄存器 有一个bit来打开或关闭中断。

SIP（supenisor interrupt pending）寄存器 指示中断是否挂起。

scause寄存器 指示中断的原因。

 **Interrupt 发生时硬件会做什么？**

  如果SIE相应bit已经被设置：清除SIE寄存器相应的bit，以阻止cpu核被其他中断打扰，SEPC寄存器保存当前PC寄存器的值，保存当前的模式，设置为supervisor mode ，当前PC的值设置成STVEC的值

**补充知识：Polling（轮询）**处理器定期检查设备的状态，以确定是否有事件处理。中断适用于不频繁发生设备需要关注的情况，但它的CPU开销较高。而高速设备要减少对中断的需求，可使用轮询轮询适用于设备操作速度快的情况，但可能浪费cpu时间。

## 定时器中断

XV6使用定时器中断来维护时钟，以及切换进程，让CPu可以在多个进程之间切换进行，使用usertrap和kernel trap的yield调用实现。

**定时器中断**必须在机器模式下处理，机器模式权限更高，但没有分页功能。

**处理流程：**

1. 初始化：Start.c中的代码会设置好处理定时器中断的环境，配置CLINT 硬件，准备一个暂存区保存寄存器，并设置好**timervec**
2. 中断处理：处理程序请求RISC-V产生个软件中断，然后立即返回，通过普通tap 机制处理中断，内核可以禁用或管理它们。


**timervec**会保存一些重要的寄存器，告诉CLINT什么时候产生下一个定时器中断，请求软件中断，是汇编代码。



# Locking

## 什么是并发？

并发是指多个指令流交错执行的情况，可能是由于多处理器并行、线程切换或中断引起的。可能会导致一个CPU在读取数据结构时，另一个CPU可能在更新它，或者多个cpu 同时修改一个数据。

## 什么是锁？

锁是一种并发控制机制，用于管理对共享资源的访问，通过确保在同一时间只有一个线程或进程可以访问特定的资源，从而防止并发冲突和数据不一致。

锁提供互斥，确保每次只有一个CPU可以持有锁，从而保护数据。如果程序员将锁与每个共享数据项关联，并且代码在使用某个数据项时总是持有相应的锁，那么该数据项只能被一个CPU使用。

锁可以避率免丢失更新；用锁打包多个操作，使它们具有原子性；锁可以维护共享数据给构的不变性

## Race Conditions

并发执行的多个线程或进程在操作共享资源时，如没有正确的同步机制，就会导制竞态条件，在例子中，2个CPU同时对链表执行push操作，最终导致CPU2的操作被覆盖，造成丢失修改。

![4AEA34B8E82F8573D9011D8C937F7E97](C:\Users\r'j'j\Documents\Tencent Files\2365751550\FileRecv\MobileFile\4AEA34B8E82F8573D9011D8C937F7E97.png)

这就需要使用锁来保证互斥，以确保避免出现race conditions

两个进程在使用下述代码获得锁，可能会同时读到if（lk→locked＝＝0），引起Race condition ，两个进程都获得了锁

```
21 void
22 acquire(struct spinlock *lk) // does not work!
23 {
24   for(;;) {
25 		if(lk->locked == 0) {
26 		lk->locked = 1;
27 		break;
28 	   }
29   }
30 }
```

**知识补充**： RISC-V使用amoswap指令保证以原子的方式执行判断和赋值的序列  示例：amoswap address，r1，V2 实现r1与r2的值交换（原子操作）

## XV6有两种类型的锁，自旋锁和睡眠锁。

XV6用struct spinlock表示自旋锁，当locked字段为0时，锁可用，非0时锁被持有。

XV6使用C库函数“_sync_lock＿test＿and＿set”实现自旋锁的获取，用上述的底层的amoswap 指令实现，确保了操作的原子性，acquire（）不断常试将lk-locked字段设为1，并检查之前的值。如果之前的值为0，则表示成功获取了锁；如果是1，则表示锁已被其他cpu持有，并继续自旋等待。获取锁后，acquire（）记录获取的CPU，lk→cpu字段由锁保护，只有持有锁时才能更改，release（）清除lk→cpu字段，然后释放锁。

**使用锁的一些基本原则：**当一个变量可能被多个CPU读取或写时，要使用锁来防止操作重叠，锁用于保护数据结构的不变量，如果一个不变量涉及多个内存位置，通常要用个锁保护这些位置，以保证不变量保持一致；锁可以保证并发的正确性，但过多的锁会降低并行性。

### 死锁和锁顺序

在内核中，如果某条代码需要同时持有多个锁，那么所有代码路径必须以相同的顺序获取这些锁，否则会发生死锁，锁的获取顺序应该成为每个函数规的规范，按照约定顺序获取锁。

例子：比如cpu1要重命名d1/x到d2/y

![image-20240909222102472](C:\Users\r'j'j\AppData\Roaming\Typora\typora-user-images\image-20240909222102472.png)

解决方法：确定所顺序，以锁顺序获取锁，比如，规定只能先获取d1的锁后获取d2的锁

## 锁和中断处理器

1. 自旋锁和中断的交互可能会引发死锁。
2. 为了避免这种死锁，如果中断处理程序使用了自旋锁，则CPU在持有该锁时必须禁止中断，在XV6中当cpu获取任何锁之后，xv6就禁上该cPu上的中断，当然中断还可以发生在其他CPu上。当在cPu上的锁被释放后，xv6就可以重启中断。

## 指令和内存顺序

1. 许多编绎器和CPU可能为了提高性能而乱序执行代码，这可能会导致并发代码出现不正确的行为，Xv6在锁的实现中使用了内存屏障（_sync＿synchronize()）来防止编译器和cpu进行不正确的重排序。

2. 内存屏障告诉编译器和CPU不要跨越屏障进行重排序加载或存储。

3. CPU的排序规则被称为内存模型。


## 睡眠锁

有时，xv6要长时间持有一个锁，而长时间拥有一个自旋锁会导制其他进程尝试获取该锁时进行长时间等待，而且进程在保持自旋锁时无法让出CPU

睡眠锁允许在等待锁释放时让出cpu，以便其他进程使用cpu，适用于处理时间较长的操作，睡眠锁在等待期间，中断可以发生在该cpu上，因此不能在中断处理程序中使用。

# Scheduling（停止一个线程的运行，并启动另个线程的过程）

## THREADS

1. XV6内核线程会共享内存

2. xv6用户进程中，每个进程有一个线程，线程之间没有共享内存


## TIMER INTERRUPTS

1. **抢战式调度** 即使用户代码本身没有出让CPU，定时器中断仍会将CPU的控制权拿走出让给线程调度器

2. **自愿式调度 **每个CPU核在一个时间只会运行一个线程，要么用户进程的线程，要么内核线程，要么是CPU对应的调度器线程，这种线程切换造成了多个线程同时运行在一个CPU的假象；每个线程要么只运行在一个cpu 上，要么它的状态被保存在上下文中，即线程永远不会运行在多个CPU核上

   知识补充：每个进程有两个线程，一个用户空间线程，个内核空间线程，并且存在一个限制使得一个进程要么运行在用户空间线程，要么为了执行系统调用或响应中断而运行在内核空间线程


## 多路复用

因为进程数量通常多于CPU数量，Xv6需要在进程之间共享CPU。多路复用可以给每个进程一种独占CPU的错觉。

多路复用的两种情况：

| 睡眠与唤醒机制                                               | 定期强制切换                       |
| ------------------------------------------------------------ | ---------------------------------- |
| 当进程等待I/O完成、子进程退出或在睡眠系统调用中等待时，XV6会进行进程切换 | 处理长时间计算不进入睡眠状态的进程 |

**上下文切换（主要指内核线程与调度器线程之间的切换）**

![AB6D6778221BB55DDD201FD2554A3AD2](C:\Users\r'j'j\Documents\Tencent Files\2365751550\FileRecv\MobileFile\AB6D6778221BB55DDD201FD2554A3AD2.png)

1. ①用户空间到内核空间：通过系统调用或中断，用户进程进入内核线程
2. ②保存当前上下文：将当前进程的上下文（寄存器和PC）保存到内核空间的内核栈

3. ③切换到当前CPU的调度器线程

4. ④切换到新进程的内核线程

5. ⑤恢复新进程的上下文，返回到新进程的用户空间


Swtch函数负责执行内核线程切换的保存和恢复工作，保存旧线程CPU寄存器状态，并恢复新线程之前保存的CPU寄存器状态；该函数的调用将切换堆栈指针和PC，确保CPU切换到新的堆栈并执行新的代码。
m organization.md…]()
