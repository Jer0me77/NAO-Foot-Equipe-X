// Generated for ALMotionRecorder version 1.14

#ifndef ALMOTIONRECORDERPROXYREMOTE_H_
#define ALMOTIONRECORDERPROXYREMOTE_H_
#include <alremoteproxies/almotionrecorderproxyposthandlerremote.h>

namespace AL
{

/// <summary>ALMotionRecorder is a very specific module for real-time motion recording in Choregraphe. Users can get a simpler interface for motion recording by using the Animation Mode. ALMotionRecorder also supports recording modes using bumpers or torso button, and selective motion replay.</summary>
class ALMotionRecorderProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALMotionRecorderProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALMotionRecorder", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALMotionRecorderProxyPostHandlerRemote post;


    /// <summary>
    /// Called by ALMemory when subcription data is updated. INTERNAL
    /// </summary>
    /// <param name="dataName"> Name of the subscribed data. </param>
    /// <param name="data"> Value of the the subscribed data </param>
    /// <param name="message"> The message give when subscribing. </param>
    void dataChanged(const std::string& dataName, const AL::ALValue& data, const std::string& message)
    {

        callVoidRemote("dataChanged" , dataName, data, message);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName()
    {

        return callRemote<std::string >("getBrokerName");
    }


    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName)
    {

        return callRemote<AL::ALValue >("getMethodHelp" , methodName);
    }


    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList()
    {

        return callRemote<std::vector<std::string> >("getMethodList");
    }


    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp()
    {

        return callRemote<AL::ALValue >("getModuleHelp");
    }


    /// <summary>
    /// Gets the method usage string. This summarises how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name)
    {

        return callRemote<std::string >("getUsage" , name);
    }


    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id)
    {

        return callRemote<bool >("isRunning" , id);
    }


    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping()
    {

        return callRemote<bool >("ping");
    }


    /// <summary>
    /// Start recording the motion in an interactive mode
    /// </summary>
    /// <param name="jointsToRecord"> Names of joints that must be recorded </param>
    /// <param name="nbPoses"> Default number of poses to record </param>
    /// <param name="extensionAllowed"> Set to true to ignore nbPoses and keep recording new poses as long as record is not manually stopped </param>
    /// <param name="mode"> Indicates which interactive mode must be used. 1 : Use right bumper to enslave and left bumper to store the pose  (deprecated); 2 : Use chest button to store the pose </param>
    void startInteractiveRecording(const std::vector<std::string>& jointsToRecord, const int& nbPoses, const bool& extensionAllowed, const int& mode)
    {

        callVoidRemote("startInteractiveRecording" , jointsToRecord, nbPoses, extensionAllowed, mode);
    }


    /// <summary>
    /// Start recording the motion in a periodic mode
    /// </summary>
    /// <param name="jointsToRecord"> Names of joints that must be recorded </param>
    /// <param name="nbPoses"> Default number of poses to record </param>
    /// <param name="extensionAllowed"> set to true to ignore nbPoses and keep recording new poses as long as record is not manually stopped </param>
    /// <param name="timeStep"> Time in seconds to wait between two poses </param>
    /// <param name="jointsToReplay"> Names of joints that must be replayed </param>
    /// <param name="replayData"> An ALValue holding data for replayed joints. It holds two ALValues. The first one is an ALValue where each line corresponds to a joint, and column elements are times of control points The second one is also an ALValue where each line corresponds to a joint, but column elements are arrays containing [float angle, Handle1, Handle2] elements, where Handle is [int InterpolationType, float dAngle, float dTime] describing the handle offsets relative to the angle and time of the point. The first bezier param describes the handle that controls the curve preceding the point, the second describes the curve following the point. </param>
    void startPeriodicRecording(const std::vector<std::string>& jointsToRecord, const int& nbPoses, const bool& extensionAllowed, const float& timeStep, const std::vector<std::string>& jointsToReplay, const AL::ALValue& replayData)
    {

        callVoidRemote("startPeriodicRecording" , jointsToRecord, nbPoses, extensionAllowed, timeStep, jointsToReplay, replayData);
    }


    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id)
    {

        callVoidRemote("stop" , id);
    }


    /// <summary>
    /// Stop recording the motion and return data
    /// </summary>
    /// <returns> Returns the recorded data as an ALValue: [[JointName1,[pos1, pos2, ...]], [JointName2,[pos1, pos2, ...]], ...] </returns>
    AL::ALValue stopAndGetRecording()
    {

        return callRemote<AL::ALValue >("stopAndGetRecording");
    }


    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version()
    {

        return callRemote<std::string >("version");
    }


    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod)
    {

        return callRemote<bool >("wait" , id, timeoutPeriod);
    }


};

}
#endif // ALMOTIONRECORDERPROXY_H_
