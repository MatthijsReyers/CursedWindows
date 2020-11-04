
#include "layouts/grid.hpp"

namespace cw
{
    GridLayout::GridLayout() 
        : GridLayout(1,1,0,0) {}
    GridLayout::GridLayout(uint16_t r, uint16_t c)
        : GridLayout(r,c,0,0) {}

    GridLayout::GridLayout(uint16_t r, uint16_t c, uint16_t hg, uint16_t vg)
    : rows(r), columns(c), horizontalGap(hg), verticalGap(vg)
    {
        this->resizeGrid();
    }

    uint16_t GridLayout::getRows() const
        {return this->rows;}
    uint16_t GridLayout::getColumns() const
        {return this->columns;}
    void GridLayout::setRows(uint16_t r)
        {this->rows = r; this->resizeGrid();}
    void GridLayout::setColumns(uint16_t c)
        {this->columns = c; this->resizeGrid();}

    uint16_t GridLayout::getHorizontalGap() const
        {return this->horizontalGap;}
    uint16_t GridLayout::getVerticalGap() const
        {return this->verticalGap;}
    void GridLayout::setHorizontalGap(uint16_t hGap)
        {this->horizontalGap = hGap; this->resizeGrid();}
    void GridLayout::setVerticalGap(uint16_t vGap)
        {this->verticalGap = vGap; this->resizeGrid();}

    /**
     * Automatically adds the widget to an empty space in the grid. The method
     * will start searching at the lower coordinates first so widgets are placed
     * from left to right and top to bottom. 
     * 
     * @throws cw::InvalidWidgetPlacement is thrown when there are no more free
     *      spaces (= EmptyWidget instances) in the grid.
     */
    void GridLayout::addWidget(std::shared_ptr<Widget> widget)
    {
        // TODO:
       
        
        // Could not find an empty widget to replace.
        throw InvalidWidgetPlacement("No space left in grid layout for widget.");
    }

    /**
     * Method for placing a widget in the grid layout at specific coordinates.
     * Note that the coordinates start at zero and increase from left to right
     * and top to bottom. (Meaning [0,0] is at the top left of the terminal).
     * 
     * @param [widget] shared pointer of widget to place at coordinates.
     * @param [x,y] coordinates of widget to delete.
     * 
     * @throws cw::InvalidWidgetPlacement is thrown when the provided coordinates 
     *      are outside the area/coordinate system of the grid.
     */
    void GridLayout::addWidget(std::shared_ptr<Widget> widget, uint16_t x, uint16_t y)
    {
        if (x >= this->columns || y >= this->rows)
            throw InvalidWidgetPlacement("Cannot place widget outside of grid.");
        
        // The onGridResize method ensures that the matrix is always the size
        // of the grid, so there is no need to check if the x,y coordinates exist.
        this->widgets[x][y] = widget;
    }

    /**
     * Method for deleting a widget in the grid layout. Practically speaking the
     * existing widget will be replaced with an empty widget. Specifing 
     * coordinates outside the grid will not cause any exceptions or modifications
     * to the Layout.
     * 
     * @param [x,y] coordinates of widget to delete.
     */
    void GridLayout::deleteWidget(uint16_t x, uint16_t y) noexcept
    {
        // Check if coordinates exist.
        if (x < this->columns || y < this->rows)
        {
            // Replace widget with empty widget.
            this->widgets[x][y] = std::make_shared<Widget>();
        }
    }


    /**
     * Method called whenever the dimensions of the grid change. This method is
     * responsible for delting the elements outside the new grid size and 
     * growing the vectors if the grid size is increased. 
     */
    void GridLayout::resizeGrid() noexcept
    {
        // Add collums if needed.
        while (this->widgets.size() < this->columns)
            this->widgets.push_back(std::vector<std::shared_ptr<Widget>>());

        // Delete collums if needed.
        while (this->widgets.size() > this->columns)
            this->widgets.pop_back();

        // Do the same for each column vector.
        for (auto column : this->widgets)
        {
            // Lengthen vector with empty widgets if needed.
            while (column.size() < this->rows)
                column.push_back(std::make_shared<Widget>());

            // Shorten vector if needed.
            while (column.size() > this->rows)
                column.pop_back();
        }
    }

    /**
     * Method called whenever the size of the layout changes, overwritten from the
     * default because resizeGrid() needs to be called upon every resize.
     */
    void GridLayout::resize(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
    {
        this->setPosition(x,y);
        this->setSize(w,h);

        // Recalculate grid positions.
        this->resizeGrid();

        // Check and call the draw callback if specified.
        if (this->onResize) this->onResize();

        this->draw();

        // Check and call the draw callback if specified.
        if (this->onDraw) this->onDraw();
    }
}