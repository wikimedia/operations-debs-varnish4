#!/bin/sh

test_description="varnishd service configtest"

. ./sharness.sh

add_syntax_error() {
  sed -i -e 's/vcl 4.0/fail fail fail/g' /etc/varnish/default.vcl
}

remove_syntax_error() {
  sed -i -e 's/fail fail fail/vcl 4.0/g' /etc/varnish/default.vcl
}

test_expect_success "restart" "
  service varnish restart
"


test_expect_success "add syntax error" "
  add_syntax_error
"

if ! [ -d /run/systemd ]; then
  # The "configtest" action is only in the sysv init script
  test_expect_success "configtest should fail" "
    test_expect_code 2 service varnish configtest
  "
fi

test_expect_success "reload should fail" "
  test_expect_code 1 service varnish reload
"

test_expect_success "restart should fail" "
  test_expect_code 1 service varnish restart
"

test_expect_success "remove syntax error" "
  remove_syntax_error
"


test_done
