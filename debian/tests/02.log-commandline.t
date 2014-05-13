#!/bin/sh

test_description="varnishlog service"

. ./sharness.sh

test_expect_success "look for logged request with varnishlog" "
  varnishlog -d -q 'ReqURL eq \"/testing.varnish\"' | grep -q check_http
"

test_expect_success "look for logged request with varnishncsa" "
  varnishncsa -d -q 'ReqURL eq \"/testing.varnish\"' | grep -q check_http
"

test_done
