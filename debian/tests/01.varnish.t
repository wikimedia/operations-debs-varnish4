#!/bin/sh

test_description="varnishd service"

. ./sharness.sh

test_expect_success "default.vcl syntax" "
  /usr/sbin/varnishd -f /etc/varnish/default.vcl -C
"

test_expect_success "varnish service running" "
  service varnish status
"

test_expect_success "make a request, expecting 503 Backend fetch failed" "
  /usr/lib/nagios/plugins/check_http -H localhost -p 6081 -u /testing.varnish -e 503 -s 'Backend fetch failed'
"

test_done
