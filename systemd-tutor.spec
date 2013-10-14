Name:		systemd-tutor
Version:	2
Release:	1%{?dist}
Summary:	Example files for systemd tutorial

Group:		Applications/System
License:	Beerware
Source0:	systemd-tutor-%{version}.tar.bz2

#BuildRequires:	
Requires:	systemd

%description
Example files for systemd tutorial


%prep
%setup -q


%build
make %{?_smp_mflags}


%install
make install ROOT=%{buildroot}


%files
/usr/bin/my_little_daemon
/usr/bin/oneshot.sh
/usr/lib/systemd/system/oneshot.service
/usr/lib/systemd/system/my_little_daemon.service
/usr/lib/systemd/system/my.service
/usr/lib/systemd/system/really-required.service
/usr/lib/systemd/system/required.service

%changelog
* Mon Oct 14 2013 Lukas Nykryn <lnykryn@redhat.com> - 2-1
- dependencies

* Mon Oct 14 2013 Lukas Nykryn <lnykryn@redhat.com> - 1-1
- oneshot.sh
- my_little_daemon


