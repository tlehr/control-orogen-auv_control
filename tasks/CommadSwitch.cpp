/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "CommadSwitch.hpp"

using namespace auv_control;

CommadSwitch::CommadSwitch(std::string const& name, TaskCore::TaskState initial_state)
    : CommadSwitchBase(name, initial_state)
{
}

CommadSwitch::CommadSwitch(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : CommadSwitchBase(name, engine, initial_state)
{
}

CommadSwitch::~CommadSwitch()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See CommadSwitch.hpp for more detailed
// documentation about them.

bool CommadSwitch::configureHook()
{
    if (! CommadSwitchBase::configureHook())
        return false;
    return true;
}
bool CommadSwitch::startHook()
{
    if (! CommadSwitchBase::startHook())
        return false;
    return true;
}
void CommadSwitch::updateHook()
{
    CommadSwitchBase::updateHook();
    
    base::LinearAngular6DCommand cmd_default;
    _cmd_in_default.readNewest(cmd_default);
    
    if(_cmd_in_optional.connected()){
        base::LinearAngular6DCommand cmd_optional;
        _cmd_in_optional.readNewest(cmd_optional);

        if((cmd_default.time - cmd_optional.time).toSeconds() < _optional_write_time.get()){
            _cmd_out.write(cmd_optional);
            return;
        }
    }
    _cmd_out.write(cmd_default);
}
void CommadSwitch::errorHook()
{
    CommadSwitchBase::errorHook();
}
void CommadSwitch::stopHook()
{
    CommadSwitchBase::stopHook();
}
void CommadSwitch::cleanupHook()
{
    CommadSwitchBase::cleanupHook();
}
