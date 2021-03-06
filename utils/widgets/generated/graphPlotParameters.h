#ifndef GRAPH_PLOT_PARAMETERS_H_
#define GRAPH_PLOT_PARAMETERS_H_
/**
 * \file graphPlotParameters.h
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
#include "graphStyle.h"

/**
 * \brief Graph Plot Parameters 
 * Graph Plot Parameters 
 **/
class GraphPlotParameters : public BaseReflection<GraphPlotParameters>
{
public:
    enum FieldId {
        GRAPHSTYLE_ID,
        WIDTH_ID,
        CENTERAT_ID,
        XGRID_ID,
        YGRID_ID,
        XSCALE_ID,
        YSCALE_ID,
        CONTRAST_ID,
        SELECTGRAPH_ID,
        FIX_TIME_VALUE_ID,
        FIX_GRID_VALUE_ID,
        GRAPH_PLOT_PARAMETERS_FIELD_ID_NUM
    };

    /** Section with variables */

    /** 
     * \brief graphStyle 
     * graphStyle 
     */
    int mGraphStyle;

    /** 
     * \brief width 
     * width 
     */
    int mWidth;

    /** 
     * \brief centerAt 
     * centerAt 
     */
    double mCenterAt;

    /** 
     * \brief xGrid 
     * xGrid 
     */
    bool mXGrid;

    /** 
     * \brief yGrid 
     * yGrid 
     */
    bool mYGrid;

    /** 
     * \brief xScale 
     * xScale 
     */
    double mXScale;

    /** 
     * \brief yScale 
     * yScale 
     */
    double mYScale;

    /** 
     * \brief contrast 
     * contrast 
     */
    double mContrast;

    /** 
     * \brief selectGraph 
     * selectGraph 
     */
    bool mSelectGraph;

    /** 
     * \brief Fix Time value 
     * Fix Time value 
     */
    bool mFixTimeValue;

    /** 
     * \brief Fix Grid value 
     * Fix Grid value 
     */
    bool mFixGridValue;

    /** Static fields init function, this is used for "dynamic" field initialization */ 
    static int staticInit();

    /** Section with getters */
    const void *getPtrById(int fieldId) const
    {
        return (const unsigned char *)(this) + fields()[fieldId]->offset;
    }
    GraphStyle::GraphStyle graphStyle() const
    {
        return static_cast<GraphStyle::GraphStyle>(mGraphStyle);
    }

    int width() const
    {
        return mWidth;
    }

    double centerAt() const
    {
        return mCenterAt;
    }

    bool xGrid() const
    {
        return mXGrid;
    }

    bool yGrid() const
    {
        return mYGrid;
    }

    double xScale() const
    {
        return mXScale;
    }

    double yScale() const
    {
        return mYScale;
    }

    double contrast() const
    {
        return mContrast;
    }

    bool selectGraph() const
    {
        return mSelectGraph;
    }

    bool fixTimeValue() const
    {
        return mFixTimeValue;
    }

    bool fixGridValue() const
    {
        return mFixGridValue;
    }

    /* Section with setters */
    void setGraphStyle(GraphStyle::GraphStyle graphStyle)
    {
        mGraphStyle = graphStyle;
    }

    void setWidth(int width)
    {
        mWidth = width;
    }

    void setCenterAt(double centerAt)
    {
        mCenterAt = centerAt;
    }

    void setXGrid(bool xGrid)
    {
        mXGrid = xGrid;
    }

    void setYGrid(bool yGrid)
    {
        mYGrid = yGrid;
    }

    void setXScale(double xScale)
    {
        mXScale = xScale;
    }

    void setYScale(double yScale)
    {
        mYScale = yScale;
    }

    void setContrast(double contrast)
    {
        mContrast = contrast;
    }

    void setSelectGraph(bool selectGraph)
    {
        mSelectGraph = selectGraph;
    }

    void setFixTimeValue(bool fixTimeValue)
    {
        mFixTimeValue = fixTimeValue;
    }

    void setFixGridValue(bool fixGridValue)
    {
        mFixGridValue = fixGridValue;
    }

    /* Section with embedded classes */
    /* visitor pattern - http://en.wikipedia.org/wiki/Visitor_pattern */
template<class VisitorType>
    void accept(VisitorType &visitor)
    {
        visitor.visit((int &)mGraphStyle,         static_cast<const EnumField *>    (fields()[GRAPHSTYLE_ID]));
        visitor.visit(mWidth,                     static_cast<const IntField *>     (fields()[WIDTH_ID]));
        visitor.visit(mCenterAt,                  static_cast<const DoubleField *>  (fields()[CENTERAT_ID]));
        visitor.visit(mXGrid,                     static_cast<const BoolField *>    (fields()[XGRID_ID]));
        visitor.visit(mYGrid,                     static_cast<const BoolField *>    (fields()[YGRID_ID]));
        visitor.visit(mXScale,                    static_cast<const DoubleField *>  (fields()[XSCALE_ID]));
        visitor.visit(mYScale,                    static_cast<const DoubleField *>  (fields()[YSCALE_ID]));
        visitor.visit(mContrast,                  static_cast<const DoubleField *>  (fields()[CONTRAST_ID]));
        visitor.visit(mSelectGraph,               static_cast<const BoolField *>    (fields()[SELECTGRAPH_ID]));
        visitor.visit(mFixTimeValue,              static_cast<const BoolField *>    (fields()[FIX_TIME_VALUE_ID]));
        visitor.visit(mFixGridValue,              static_cast<const BoolField *>    (fields()[FIX_GRID_VALUE_ID]));
    }

    GraphPlotParameters()
    {
        DefaultSetter setter;
        accept(setter);
    }

    GraphPlotParameters(
          GraphStyle::GraphStyle graphStyle
        , int width
        , double centerAt
        , bool xGrid
        , bool yGrid
        , double xScale
        , double yScale
        , double contrast
        , bool selectGraph
        , bool fixTimeValue
        , bool fixGridValue
    )
    {
        mGraphStyle = graphStyle;
        mWidth = width;
        mCenterAt = centerAt;
        mXGrid = xGrid;
        mYGrid = yGrid;
        mXScale = xScale;
        mYScale = yScale;
        mContrast = contrast;
        mSelectGraph = selectGraph;
        mFixTimeValue = fixTimeValue;
        mFixGridValue = fixGridValue;
    }

    friend ostream& operator << (ostream &out, GraphPlotParameters &toSave)
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
#endif  //GRAPH_PLOT_PARAMETERS_H_
