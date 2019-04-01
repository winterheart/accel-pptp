ACCEL-PPTP
==========
The **ACCEL-PPTP** is PPTP client plugin for PPP.
ACCEL-PPTP uses kernel module to increase performance and decrease system usage.
For more documentation about PPTP visit POPTOP web site.

Requirment
----------
* Modern linux distribution
* kernel-2.6.36 or later with PPTP support
* pppd-2.4.2 or later
* CMake 3.1 or later

Compilation
-----------
First at all, make sure that your kernel properly configured. You should have
pptp.ko kernel module. Here some hints, how to enable support in kernel (tested
on 2.6.39):

```
[*] Networking support ->
  Networking options ->
    [*] TCP/IP networking ->
      <M> IP: GRE demultiplexer ->
        <M> IP: GRE tunnels over IP ->
Device Drivers ->
  [*] Network device support ->
    <M> PPP (point-to-point protocol) support ->
      <M> PPP over IPv4 (PPTP)
```

Don't forget load module pptp.ko when connecting:

```
modprobe pptp
```

Untar tarball:

```
tar jxvf accel-pptp-<VER>.tar.bz2
```

Create build directory:

```
mkdir accel-pptp_build
cd accel-pptp_build
```

Now you can compile plugin:

```
cmake ../accel-pptp-<VER>
make
```

Installation
------------
Just `make install` from accel-pptp_build directory.

Configuration
-------------
If you are beginner in PPTP please read documentation available on POPTOP web
site.

Configuration is same as original pptpd and pptp.
Exception in configuration of client is:
replace line in peer config file (for instance, /etc/ppp/peers/my_vpn):
  pty "pptp x.x.x.x ...." 
to 
  plugin "/usr/lib/pptp.so" (path may differ)
  pptp_server x.x.x.x (required)
  pptp_phone xxxx (optional)
  pptp_window xxx (optional) - this is sliding window size (at current time automatic algorithm is not implemented),
                               set it to  3-10 for low-speed connections,
                                      to   >10 for hi-speed connections. 
  
Remove `lock` option in `/etc/ppp/options.pptp`, `/etc/ppp/options.pptpd` or similar if it exists.

See configuration example in example directory.


Warning
-------

* This driver conflicts with ip_gre driver (in kernel), so make sure that ip_gre is not built-in or loaded at run time.
* Never mix connections of accel-pptp and original pptpd, before starting accel-pptp make sure that no connections of
original pptpd exists.
* If you are upgrading pppd, don't forget recompile and reinstall pptp plugin too.


Thanks
------
Author of original accel-pptp code Dmitry Kozlov <xeb@mail.ru>

Thanks to Kirill Yushkov for debug support and donations.

https://github.com/winterheart/accel-pptp/
