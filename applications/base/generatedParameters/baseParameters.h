#ifndef BASE_PARAMETERS_H_
#define BASE_PARAMETERS_H_
/**
 * \file baseParameters.h
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "reflection.h"
#include "defaultSetter.h"
#include "printerVisitor.h"

/*
 *  Embed includes.
 */
/*
 *  Additional includes for Composite Types.
 */

using namespace corecvs;

/*
 *  Additional includes for Pointer Types.
 */

namespace corecvs {
}
/*
 *  Additional includes for enum section.
 */
#include "rotationPresets.h"
#include "interpolationType.h"

/**
 * \brief Base parameters 
 * Base parameters 
 **/
class BaseParameters : public BaseReflection<BaseParameters>
{
public:
    enum FieldId {
        ROTATION_ID,
        MIRROR_ID,
        SWAPCAMERAS_ID,
        FILTERLOCK_ID,
        ENABLEFILTERGRAPH_ID,
        DOWNSAMPLE_ID,
        H_ID,
        W_ID,
        AUTOH_ID,
        AUTOW_ID,
        X_ID,
        Y_ID,
        INTERPOLATIONTYPE_ID,
        BASE_PARAMETERS_FIELD_ID_NUM
    };

    /** Section with variables */

    /** 
     * \brief rotation 
     * rotation 
     */
    int mRotation;

    /** 
     * \brief mirror 
     * mirror 
     */
    bool mMirror;

    /** 
     * \brief swapCameras 
     * swapCameras 
     */
    bool mSwapCameras;

    /** 
     * \brief filterLock 
     * filterLock 
     */
    bool mFilterLock;

    /** 
     * \brief enableFilterGraph 
     * enableFilterGraph 
     */
    bool mEnableFilterGraph;

    /** 
     * \brief downsample 
     * Prescale coefficient for input image 
     */
    double mDownsample;

    /** 
     * \brief h 
     * Input crop height 
     */
    int mH;

    /** 
     * \brief w 
     * Input crop width 
     */
    int mW;

    /** 
     * \brief autoH 
     * Select crop height so that full image will fit 
     */
    bool mAutoH;

    /** 
     * \brief autoW 
     * Select crop width so that full image will fit 
     */
    bool mAutoW;

    /** 
     * \brief x 
     * Scaled image horizonal shift before crop 
     */
    int mX;

    /** 
     * \brief y 
     * Scaled image vertical shift before crop 
     */
    int mY;

    /** 
     * \brief InterpolationType 
     * InterpolationType 
     */
    int mInterpolationType;

    /** Static fields init function, this is used for "dynamic" field initialization */ 
    static int staticInit();

    /** Section with getters */
    const void *getPtrById(int fieldId) const
    {
        return (const unsigned char *)(this) + fields()[fieldId]->offset;
    }
    RotationPresets::RotationPresets rotation() const
    {
        return static_cast<RotationPresets::RotationPresets>(mRotation);
    }

    bool mirror() const
    {
        return mMirror;
    }

    bool swapCameras() const
    {
        return mSwapCameras;
    }

    bool filterLock() const
    {
        return mFilterLock;
    }

    bool enableFilterGraph() const
    {
        return mEnableFilterGraph;
    }

    double downsample() const
    {
        return mDownsample;
    }

    int h() const
    {
        return mH;
    }

    int w() const
    {
        return mW;
    }

    bool autoH() const
    {
        return mAutoH;
    }

    bool autoW() const
    {
        return mAutoW;
    }

    int x() const
    {
        return mX;
    }

    int y() const
    {
        return mY;
    }

    InterpolationType::InterpolationType interpolationType() const
    {
        return static_cast<InterpolationType::InterpolationType>(mInterpolationType);
    }

    /* Section with setters */
    void setRotation(RotationPresets::RotationPresets rotation)
    {
        mRotation = rotation;
    }

    void setMirror(bool mirror)
    {
        mMirror = mirror;
    }

    void setSwapCameras(bool swapCameras)
    {
        mSwapCameras = swapCameras;
    }

    void setFilterLock(bool filterLock)
    {
        mFilterLock = filterLock;
    }

    void setEnableFilterGraph(bool enableFilterGraph)
    {
        mEnableFilterGraph = enableFilterGraph;
    }

    void setDownsample(double downsample)
    {
        mDownsample = downsample;
    }

    void setH(int h)
    {
        mH = h;
    }

    void setW(int w)
    {
        mW = w;
    }

    void setAutoH(bool autoH)
    {
        mAutoH = autoH;
    }

    void setAutoW(bool autoW)
    {
        mAutoW = autoW;
    }

    void setX(int x)
    {
        mX = x;
    }

    void setY(int y)
    {
        mY = y;
    }

    void setInterpolationType(InterpolationType::InterpolationType interpolationType)
    {
        mInterpolationType = interpolationType;
    }

    /* Section with embedded classes */
    /* visitor pattern - http://en.wikipedia.org/wiki/Visitor_pattern */
template<class VisitorType>
    void accept(VisitorType &visitor)
    {
        visitor.visit((int &)mRotation,           static_cast<const EnumField *>    (fields()[ROTATION_ID]));
        visitor.visit(mMirror,                    static_cast<const BoolField *>    (fields()[MIRROR_ID]));
        visitor.visit(mSwapCameras,               static_cast<const BoolField *>    (fields()[SWAPCAMERAS_ID]));
        visitor.visit(mFilterLock,                static_cast<const BoolField *>    (fields()[FILTERLOCK_ID]));
        visitor.visit(mEnableFilterGraph,         static_cast<const BoolField *>    (fields()[ENABLEFILTERGRAPH_ID]));
        visitor.visit(mDownsample,                static_cast<const DoubleField *>  (fields()[DOWNSAMPLE_ID]));
        visitor.visit(mH,                         static_cast<const IntField *>     (fields()[H_ID]));
        visitor.visit(mW,                         static_cast<const IntField *>     (fields()[W_ID]));
        visitor.visit(mAutoH,                     static_cast<const BoolField *>    (fields()[AUTOH_ID]));
        visitor.visit(mAutoW,                     static_cast<const BoolField *>    (fields()[AUTOW_ID]));
        visitor.visit(mX,                         static_cast<const IntField *>     (fields()[X_ID]));
        visitor.visit(mY,                         static_cast<const IntField *>     (fields()[Y_ID]));
        visitor.visit((int &)mInterpolationType,  static_cast<const EnumField *>    (fields()[INTERPOLATIONTYPE_ID]));
    }

    BaseParameters()
    {
        DefaultSetter setter;
        accept(setter);
    }

    BaseParameters(
          RotationPresets::RotationPresets rotation
        , bool mirror
        , bool swapCameras
        , bool filterLock
        , bool enableFilterGraph
        , double downsample
        , int h
        , int w
        , bool autoH
        , bool autoW
        , int x
        , int y
        , InterpolationType::InterpolationType interpolationType
    )
    {
        mRotation = rotation;
        mMirror = mirror;
        mSwapCameras = swapCameras;
        mFilterLock = filterLock;
        mEnableFilterGraph = enableFilterGraph;
        mDownsample = downsample;
        mH = h;
        mW = w;
        mAutoH = autoH;
        mAutoW = autoW;
        mX = x;
        mY = y;
        mInterpolationType = interpolationType;
    }

    friend ostream& operator << (ostream &out, BaseParameters &toSave)
    {
        PrinterVisitor printer(out);
        toSave.accept<PrinterVisitor>(printer);
        return out;
    }

    void print ()
    {
        cout << *this;
    }
};
#endif  //BASE_PARAMETERS_H_
