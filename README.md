systemd-tutor
=============

Example files for systemd tutorial.

You can find few examples of daemons and units that can help you understand
and learn how systemd as init system works.

Get Started
=============
To build example daemons open terminal and type:

> make

To install binaries and systemd units use the command:

> make install

Now you have your playground ready. Try

> systemctl start oneshot.service

> journalctl -u oneshot.service
