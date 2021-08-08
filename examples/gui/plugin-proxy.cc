#include "plugin-proxy.hh"

PluginProxy::PluginProxy(QObject *parent) : QObject(parent) {}

ParameterProxy *PluginProxy::param(clap_id paramId) const {
   auto it = parameters_.find(paramId);
   return it != parameters_.end() ? it->second : nullptr;
}

QString PluginProxy::toString() const { return "Plugin"; }

void PluginProxy::defineParameter(const clap_param_info &info)
{
   parameters_.emplace(info.id, new ParameterProxy(info, this));
}