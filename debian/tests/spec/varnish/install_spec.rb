require 'spec_helper'

describe package('varnish') do
  it { should be_installed }
end

describe service('varnish') do
  it { should be_enabled }
  it { should be_running }
end

describe port(6081) do
  it { should be_listening.with('tcp') }
end

describe port(6082) do
  it { should be_listening.with('tcp') }
end

describe command('varnishadm ping') do
  its(:exit_status) { should eq 0 }
  its(:stdout) { should match( /PONG/) }
end
