require 'spec_helper'

describe command('/usr/sbin/varnishd -C -f /etc/varnish/default.vcl') do
  its(:exit_status) { should eq 0 }
end
