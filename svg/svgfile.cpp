#include "svgfile.h"

const std::string svgHeader =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
    "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" ";

const std::string svgEnding = "\n\n</svg>\n";

/// Effets "Boule en relief", voir données à la fin de ce fichier
extern const std::string svgBallGradients;

std::set<std::string> Svgfile::s_openfiles;

bool Svgfile::s_verbose = true;

Svgfile::Svgfile(std::string _filename, int _width, int _height) :
    m_filename{_filename}, m_width{_width}, m_height{_height}
{
    if (s_verbose)
        std::cout << "Opening SVG output file : "
                  << m_filename << std::endl;

    if ( s_openfiles.count(m_filename) )
        throw std::runtime_error( "File " + m_filename + " already open !" );

    m_ostrm.open(m_filename);
    s_openfiles.insert(m_filename);

    if (!m_ostrm)
    {
        std::cout << "Problem opening " << m_filename << std::endl;
        throw std::runtime_error("Could not open file " + m_filename );
    }

    if (s_verbose)
        std::cout << "OK" << std::endl;

    // Writing the header into the SVG file
    m_ostrm << svgHeader;
    m_ostrm << "width=\"" << m_width << "\" height=\"" << m_height << "\">\n\n";
}

Svgfile::~Svgfile()
{
    // Writing the ending into the SVG file
    m_ostrm << svgEnding;

    // Removing this file from the list of open files
    s_openfiles.erase(m_filename);

    // No need to explicitly close the ofstream object (automatic upon destruction)
}

// Helper templated function
template<typename T>
std::string attrib(std::string name, T val)
{
    std::ostringstream oss;
    oss << name << "=\"" << val << "\" ";
    return oss.str();
}

void Svgfile::addDisk(double x, double y, double r, std::string color)
{
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << attrib("fill", color )
            << "/>\n";
}

void Svgfile::addSoleil(double x, double y, double r, std::string color)
{
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << " fill=\"url(#"
            << color <<")\" />\n";
}

void Svgfile::addCircle(double x, double y, double r, double ep, std::string color)
{
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << attrib("fill", "none")
            << attrib("stroke", color )
            << attrib("stroke-width", ep )
            << "/>\n";
}

/// <polygon points="200,10 250,190 160,210" style="fill:lime;stroke:purple;stroke-width:1" />
void Svgfile::addTriangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, std::string colorFill,
                          double thickness, std::string colorStroke)
{

    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3
            << "\" style=\"fill:" << colorFill
            << ";stroke:" << colorStroke
            << ";stroke-width:" << thickness
            << "\" />\n";
}


void Svgfile::addTriangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, std::string colorFill)
{
    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3
            << "\" style=\"fill:" << colorFill
            << "\" />\n";
}

void Svgfile::addRectangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, double x4, double y4, std::string colorFill)
{
    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3 << " "
            << x4 << "," << y4
            << "\" style=\"fill:" << colorFill
            << "\" />\n";
}

void Svgfile::addRectangle(double x, double y, double width, double height,
                            std::string color)
{
    m_ostrm << "<rect x=\""
            << x << "\" y=\""
            << y << "\" width=\""
            << width << "\" height=\""
            << height << "\" fill=\"url(#"
            << color <<")\" />\n";
}

void Svgfile::addTraits(double x, double y, double width, double height,
                        std::string color1, std::string color2)
{
    m_ostrm << "<rect x=\""
            << x << "\" y=\""
            << y << "\" width=\""
            << width << "\" height=\""
            << height << "\" style=\"fill:"
            << color1 << ";stroke:"
            << color2 << ";stroke-width:"
            << 0.5*height << ";fill-opacity:"
            << 0.1 << ";stroke-opacity:"
            << 0.1
            << "\" />\n";
}

void Svgfile::addRectangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, double x4, double y4, std::string colorFill,
                          double thickness, std::string colorStroke)
{
    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3 << " "
            << x4 << "," << y4
            << "\" style=\"fill:" << colorFill
            << ";stroke:" << colorStroke
            << ";stroke-width:" << thickness
            << "\" />\n";
}

void Svgfile:: linearGradient(std::string grad, double x1, double y1, double x2, double y2,
                           double offset1, std::string color1, double opacity,
                           double offset2, std::string color2)
{
    m_ostrm <<"<defs>\n";
    m_ostrm << "<linearGradient id=\""
            << grad << "\" x1=\""
            << x1 << "%\" y1=\""
            << y1 << "%\" x2=\""
            << x2 << "%\" y2=\""
            << y2 << "%\">\n";

    m_ostrm << "<stop offset=\"" << offset1
            << "%\" style=\"stop-color:" << color1
            << ";stop-opacity:" << opacity
            << "\" />\n";
    m_ostrm << "<stop offset=\"" << offset2
            << "%\" style=\"stop-color:" << color2
            << ";stop-opacity:" << opacity
            << "\" />\n";
    m_ostrm << "</linearGradient>\n";
    m_ostrm << "</defs>\n";
}

void Svgfile:: radialGradient(std::string grad, double cx, double cy, double r, double fx, double fy,
                           double offset1, std::string color1, double opacity1,
                           double offset2, std::string color2, double opacity2)
{
    m_ostrm <<"<defs>\n";
    m_ostrm << "<radialGradient id=\""
            << grad << "\" cx=\""
            << cx << "%\" cy=\""
            << cy << "%\" r=\""
            << r << "%\" fx=\""
            << fx << "%\" fy=\""
            << fy << "%\">\n";

    m_ostrm << "<stop offset=\"" << offset1
            << "%\" style=\"stop-color:" << color1
            << ";stop-opacity:" << opacity1
            << "\" />\n";
    m_ostrm << "<stop offset=\"" << offset2
            << "%\" style=\"stop-color:" << color2
            << ";stop-opacity:" << opacity2
            << "\" />\n";
    m_ostrm << "</radialGradient>\n";
    m_ostrm << "</defs>\n";
}

void Svgfile::addLine(double x1, double y1, double x2, double y2, std::string color)
{
    m_ostrm << "<line "
            << attrib("x1", x1)
            << attrib("y1", y1)
            << attrib("x2", x2)
            << attrib("y2", y2)
            << attrib("stroke", color)
            << "/>\n";
}

void Svgfile::addCross(double x, double y, double span, std::string color)
{
    addLine(x-span, y-span, x+span, y+span, color);
    addLine(x-span, y+span, x+span, y-span, color);
}

void Svgfile::addText(double x, double y, std::string text, std::string color)
{
    /// <text x="180" y="60">Un texte</text>
    m_ostrm << "<text "
            << attrib("x", x)
            << attrib("y", y)
            << attrib("fill", color)
            << ">" << text << "</text>\n";
}

void Svgfile::addText(double x, double y, double val, std::string color)
{
    std::ostringstream oss;
    oss << val;
    addText(x, y, oss.str(), color);
}

void Svgfile::addGrid(double span, bool numbering, std::string color)
{
    double y=0;
    while (y<=m_height)
    {
        addLine(0, y, m_width, y, color);
        if (numbering)
            addText(5, y-5, y, color);
        y+=span;
    }

    double x=0;
    while (x<=m_width)
    {
        addLine(x, 0, x, m_height, color);
        if (numbering)
            addText(x+5, 15, x, color);
        x+=span;
    }
}

std::string Svgfile::makeRGB(int r, int g, int b)
{
    std::ostringstream oss;
    oss << "rgb(" << r << "," << g << "," << b << ")";
    return oss.str();
}
