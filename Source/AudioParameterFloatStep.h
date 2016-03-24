/*
  ==============================================================================

    AudioParameterFloatStep.h
    Created: 18 Mar 2016 5:09:22pm
    Author:  John Flynn

  ==============================================================================
*/

#ifndef AUDIOPARAMETERFLOATSTEP_H_INCLUDED
#define AUDIOPARAMETERFLOATSTEP_H_INCLUDED


//==============================================================================
/**
    Subclass of ParameterSlider that allows stepped controls when used in 
    conjunction with ParameterSliderStep. (Overrides getNumSteps() method.)
*/
class AudioParameterFloatStep   : public AudioParameterFloat
{
public:
    AudioParameterFloatStep (String pid, String nm, NormalisableRange<float> r, float def)
       : AudioParameterFloat {pid, nm, r, def}
    {
    }

    //using AudioParameterFloat::AudioParameterFloat; // using APF's constructor C++11
                                                      // not compatible with MSVS 2013

    int getNumSteps() const
    {
        return static_cast<int> ((range.end - range.start) / range.interval);
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioParameterFloatStep)
};


#endif  // AUDIOPARAMETERFLOATSTEP_H_INCLUDED
