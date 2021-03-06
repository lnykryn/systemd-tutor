ROOT=/

VERSION := $(shell awk '/Version:/ { print $$2 }' systemd-tutor.spec)
RELEASE := $(shell awk '/Release:/ { print $$2 }' systemd-tutor.spec | sed 's|%{?dist}||g')
TAG=systemd-tutor-$(VERSION)-$(RELEASE)

all:
	make -C src

install:
	mkdir -p $(ROOT)/etc/ $(ROOT)/usr/bin
	mkdir -p $(ROOT)/usr/lib/systemd/system
	mkdir -p $(ROOT)/usr/share/doc/systemd-tutor
	
	install -m755 oneshot.sh $(ROOT)/usr/bin
	cp -af systemd/* $(ROOT)/usr/lib/systemd/
	install -m644 etc/my_little_daemon.conf $(ROOT)/etc/
	cp -af docs/* $(ROOT)/usr/share/doc/systemd-tutor/
	
	make install ROOT=$(ROOT) -C src

tag:
	@git tag -a -f -m "Tag as $(TAG)" $(TAG)
	@echo "Tagged as $(TAG)"

clean:
	make clean -C src
	@rm -fv *~ changenew ChangeLog.old *bz2 *sha1sum
	@find . -name "*~" -exec rm -v -f {} \;

archive: clean tag
	@git archive --format=tar --prefix=systemd-tutor-$(VERSION)/ HEAD > systemd-tutor-$(VERSION).tar
	@mkdir -p systemd-tutor-$(VERSION)/
	@tar --append -f systemd-tutor-$(VERSION).tar systemd-tutor-$(VERSION)
	@bzip2 -f systemd-tutor-$(VERSION).tar
	@rm -rf systemd-tutor-$(VERSION)
	@echo "The archive is at systemd-tutor-$(VERSION).tar.bz2"
	@sha1sum systemd-tutor-$(VERSION).tar.bz2 > systemd-tutor-$(VERSION).sha1sum
	@echo systemd-tutor-$(VERSION).sha1sum >> .git/info/exclude
	@echo systemd-tutor-$(VERSION).tar.bz2 >> .git/info/exclude

package: archive
	@mkdir -p $(HOME)/rpmbuild/BUILD $(HOME)/rpmbuild/RPMS $(HOME)/rpmbuild/SOURCES $(HOME)/rpmbuild/SPECS $(HOME)/rpmbuild/SRPMS
	@cp systemd-tutor.spec $(HOME)/rpmbuild/SPECS
	@cp systemd-tutor-$(VERSION).tar.bz2 $(HOME)/rpmbuild/SOURCES
	@rpmbuild -ba systemd-tutor.spec
	
