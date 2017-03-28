//
// Created by Stephen Clyde on 3/4/17.
//

#include "Region.h"
#include "Utils.h"
#include "World.h"
#include "Nation.h"
#include "State.h"
#include "County.h"
#include "City.h"

#include <iomanip>

const std::string regionDelimiter = "^^^";
const int TAB_SIZE = 4;
unsigned int Region::m_nextId = 0;

Region* Region::create(std::istream &in)
{
    Region* region = nullptr;
    std::string line;
    std::getline(in, line);
    if (line!="")
    {
        region = create(line);
        if (region!= nullptr)
            region->loadChildren(in);
    }
    return region;
}
Region* Region::create(const std::string& data)
{
    Region* region = nullptr;
    std::string regionData;
    unsigned long commaPos = (int) data.find(",");
    if (commaPos != std::string::npos)
    {
        std::string regionTypeStr = data.substr(0,commaPos);
        regionData = data.substr(commaPos+1);

        bool isValid;
        RegionType regionType = (RegionType) convertStringToInt(regionTypeStr, &isValid);

        if (isValid)
        {
            region = create(regionType, regionData);
        }

    }

    return region;
}

Region* Region::create(RegionType regionType, const std::string& data)
{
    Region* region = nullptr;
    std::string fields[3];
    if (split(data, ',', fields, 3)) {

        // Create the region based on type
        switch (regionType) {
            case WorldType:
                region = new World();
                break;
            case NationType:
                region = new Nation(fields);
                break;
       // DONE: Add cases for State, County, and City
            case StateType:
                region = new State(fields);
                break;
            case CountyType:
                region = new County(fields);
                break;
            case CityType:
                region = new City(fields);
                break;
            default:
                break;
        }

        // If the region isn't valid, get rid of it
        if (region != nullptr && !region->getIsValid()) {
            delete region;
            region = nullptr;
        }
    }

    return region;
}

std::string Region::regionLabel(RegionType regionType)
{
    std::string label = "Unknown";
    switch (regionType)
    {
        case Region::WorldType:
            label = "World";
            break;
        case Region::NationType:
            label = "Nation";
            break;
        case Region::StateType:
            label = "State";
            break;
        case Region::CountyType:
            label = "County";
            break;
        case Region::CityType:
            label = "City";
            break;
        default:
            break;
    }
    return label;
}

Region::Region() { }

Region::Region(RegionType type, const std::string data[]) :
        m_id(getNextId()), m_regionType(type), m_isValid(true)
{
    m_name = data[0];
    m_population = convertStringToUnsignedInt(data[1], &m_isValid);
    if (m_isValid)
        m_area = convertStringToDouble(data[2], &m_isValid);
}

Region::~Region()
{
    // DONE: cleanup any dynamically allocated objects
    if (subRegions != nullptr)
    {
        for (int index = 0; index < subregionCount; index++)
        {
            delete subRegions[index];
        }
        delete[] subRegions;
    }
}

std::string Region::getRegionLabel() const
{
    return regionLabel(getType());
}

unsigned int Region::computeTotalPopulation()
{
    // DONE: implement computeTotalPopulation, such that the result is m_population + the total population for all sub-regions
    unsigned int total = m_population;

    for (int index = 0; index < subregionCount; index++)
    {
        total += subRegions[index]->computeTotalPopulation();
    }

    return total;
}

void Region::list(std::ostream& out)
{
    out << std::endl;
    out << getName() << ":" << std::endl;

    // DONE: implement the loop in the list method
    // foreach subregion, print out
    //      id    name

    for (int index = 0; index < subregionCount; index++)
    {
        out << m_id << " " << m_name << std::endl;
    }
}

void Region::display(std::ostream& out, unsigned int displayLevel, bool showChild)
{
    if (displayLevel>0)
    {
        out << std::setw(displayLevel * TAB_SIZE) << " ";
    }

    // DONE: compute the totalPopulation using a method
    unsigned totalPopulation = computeTotalPopulation();
    double area = getArea();
    double density = (double) totalPopulation / area;


    out << std::setw(6) << getId() << "  "
        << getName() << ", population="
        << totalPopulation
        << ", area=" << area
        << ", density=" << density << std::endl;

    if (showChild)
    {
        // DONE: implement loop in display method
        // foreach subregion
        //      display that subregion at displayLevel+1 with the same showChild value
        for (int index = 0; index < subregionCount; index++)
        {
            subRegions[index]->display(out, displayLevel + 1, showChild);
        }
    }
}

void Region::save(std::ostream& out)
{
    out << getType()
        << "," << getName()
        << "," << getPopulation()
        << "," << getArea()
        << std::endl;

    // DONE: implement loop in save method to save each sub-region
    // foreach subregion,
    //      save that region

    for (int index = 0; index < subregionCount; index++)
    {
        out << "  " << subRegions[index]->getType()
            << "," << subRegions[index]->getName()
            << "," << subRegions[index]->getPopulation()
            << "," << subRegions[index]->getArea()
            << std::endl;
    }

    out << regionDelimiter << std::endl;
}

void Region::validate()
{
    m_isValid = (m_area!=UnknownRegionType && m_name!="" && m_area>=0);
}

void Region::loadChildren(std::istream& in)
{
    std::string line;
    bool done = false;
    while (!in.eof() && !done)
    {
        std::getline(in, line);
        if (line==regionDelimiter)
        {
            done = true;
        }
        else
        {
            Region* child = create(line);
            if (child!= nullptr)
            {
                // DONE: Add the new sub-region to this region
                addChild(child);
                child->loadChildren(in);

            }
        }
    }
}

unsigned int Region::getNextId()
{
    if (m_nextId==UINT32_MAX)
        m_nextId=1;

    return m_nextId++;
}

void Region::addChild(Region* newChild)
{
    ++subregionCount;

    if (m_allocated == 0)
    {
        m_allocated++;
        subRegions = new Region*[m_allocated];
    }

    if (subregionCount == m_allocated)
    {
        resize();
    }

    subRegions[subregionCount - 1] = newChild;
}

void Region::resize()
{
    Region* carl[m_allocated];

    for (unsigned int index = 0; index < m_allocated; index++)
    {
        carl[index] = subRegions[index];
    }

    unsigned int xtemp = m_allocated;
    m_allocated *= 2;

    subRegions = new Region*[m_allocated];

    for (unsigned int index = 0; index < xtemp; index++)
    {
        subRegions[index] = carl[index];
    }

    delete [] carl;
}

Region* Region::searchSubregionsByID(Region* search, unsigned int id)
{
    for (unsigned int index = 0; index < search->getSubRegionCount(); index++)
    {
        if (search->getId() != id)
        {
            searchSubregionsByID(search->subRegions[index], id);
        }

        return search->subRegions[index];
    }

    return 0;
}

unsigned int Region::searchByIndex(Region* search, unsigned int index, unsigned int id)
{
    for (unsigned int i = 0; i < search->getSubRegionCount(); i++)
    {
        if (search->subRegions[index]->getId() == id)
        {
            index = i;
        }
    }
    //if (search->subRegions[index]->getId() != id)
    //{
        //return searchByIndex(search, index + 1, id);
    //}

    return index;
}

void Region::remove(Region* &toRemove, unsigned int index)
{
    delete toRemove->subRegions[index];

    for (unsigned int i = index; i < toRemove->getSubRegionCount() - 1; i++)
    {
        toRemove->subRegions[i] = toRemove->subRegions[i + 1];
    }
}