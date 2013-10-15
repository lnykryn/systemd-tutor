Name:		systemd-tutor
Version:	4
Release:	1%{?dist}
Summary:	Example files for systemd tutorial

Group:		Applications/System
License:	Beerware
Source0:	systemd-tutor-%{version}.tar.bz2

BuildRequires:	systemd
BuildRequires:	systemd-devel
BuildRequires:  readline-devel
Requires:	systemd
Requires:	systemd-libs

%description
Example files for systemd tutorial


%prep
%setup -q


%build
make %{?_smp_mflags}


%install
make install ROOT=%{buildroot}

%post
if [ $1 -eq 1 ] ; then
    # Initial installation
    /usr/bin/systemctl daemon-reload >/dev/null 2>&1 || :
    /usr/bin/systemctl enable clumsy.service >/dev/null 2>&1 || :
    /usr/bin/systemctl start clumsy.service >/dev/null 2>&1 || :
    /usr/bin/systemctl enable instanced.socket >/dev/null 2>&1 || :
    /usr/bin/systemctl start instanced.socket >/dev/null 2>&1 || :
fi

%preun
if [ $1 -eq 0 ] ; then
    # Package removal, not upgrade
    /usr/bin/systemctl --no-reload disable clumsy.service > /dev/null 2>&1 || :
    /usr/bin/systemctl stop clumsy.service > /dev/null 2>&1 || :
    /usr/bin/systemctl --no-reaload disable instanced.socket >/dev/null 2>&1 || :
    /usr/bin/systemctl stop instanced.socket >/dev/null 2>&1 || :
fi

%postun
/bin/systemctl daemon-reload >/dev/null 2>&1 || :
if [ $1 -ge 1 ] ; then
    # Package upgrade, not uninstall
    /usr/bin/systemctl restart clumsy.service >/dev/null 2>&1 || :
    /usr/bin/systemctl restart instanced.service >/dev/null 2&1 || :
fi


%files
/usr/bin/my_little_daemon
/usr/bin/oneshot.sh
/usr/bin/screamer
%{_bindir}/instanced
/usr/lib/systemd/system/oneshot.service
/usr/lib/systemd/system/my_little_daemon.service
/usr/lib/systemd/system/my.service
/usr/lib/systemd/system/really-required.service
/usr/lib/systemd/system/required.service
/usr/lib/systemd/system/screamer.service
/usr/lib/systemd/system/useless.target
/usr/lib/systemd/system/clumsy.service
%{_unitdir}/instanced.socket
%{_unitdir}/instanced@.service
%{_unitdir}/instanced.target
/usr/share/doc/%{name}/tasks.txt
/usr/share/doc/%{name}/solution.txt
%config(noreplace) /etc/my_little_daemon.conf

%changelog
* Tue Oct 15 2013 Václav Pavlín <vpavlin@redhat.com> - 3-1
- screamer
- clumsy.service
- target practice
- tasks

* Mon Oct 14 2013 Lukas Nykryn <lnykryn@redhat.com> - 2-1
- dependencies

* Mon Oct 14 2013 Lukas Nykryn <lnykryn@redhat.com> - 1-1
- oneshot.sh
- my_little_daemon


