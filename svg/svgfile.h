﻿#ifndef SVGFILE_H_INCLUDED
#define SVGFILE_H_INCLUDED

#include <string>
#include <fstream>
#include <set>
#include <iostream>
#include <sstream>

constexpr char defcol[] = "black";

class Svgfile
{
    public:
        Svgfile(std::string _filename = "dessin.svg", int _width=1000, int _height=800);
        ~Svgfile();

        void addDisk(double x, double y, double r, std::string color=defcol);
        void addSoleil(double x, double y, double r, std::string color);
        void addCircle(double x, double y, double r, double ep, std::string color=defcol);
        void addTriangle(double x1, double y1, double x2, double y2,
                         double x3, double y3, std::string colorFill,
                          double thickness, std::string colorStroke);
        void addTriangle(double x1, double y1, double x2, double y2,
                         double x3, double y3, std::string colorFill=defcol);
        void addRectangle(double x1, double y1, double x2, double y2,
                         double x3, double y3, double x4, double y4,
                         std::string colorFill, double thickness, std::string colorStroke);
        void addRectangle(double x, double y, double width, double height,
                         double x3, double y3, double x4, double y4, std::string colorFill=defcol);
        void addRectangle(double x, double y, double width, double height,
                            std::string color);
        void addTraits(double x, double y, double width, double height,
                       std::string color1, std::string color2);
        void linearGradient(std::string grad, double x1, double y1, double x2, double y2,
                           double offset1, std::string color1, double opacity,
                           double offset2, std::string color2);
        void radialGradient(std::string grad, double cx, double cy, double r, double fx, double fy,
                           double offset1, std::string color1, double opacity1,
                           double offset2, std::string color2, double opacity2);
        void addLine(double x1, double y1, double x2, double y2, std::string color);
        void addLine(double x1, double y1, double x2, double y2, double width, std::string color=defcol);
        void addLineG(double x1, double y1, double x2, double y2, double width, std::string id);
        void addCross(double x, double y, double span, std::string color=defcol);
        void addText(double x, double y, std::string text, std::string color=defcol);
        void addText(double x, double y, double val, std::string color=defcol);

        void addGrid(double span=100.0, bool numbering=true, std::string color="lightgrey");

        static std::string makeRGB(int r, int g, int b);

        /// Type non copiable
        Svgfile(const Svgfile&) = delete;
        Svgfile& operator=(const Svgfile&) = delete;

        static bool s_verbose;

    private:
        std::string m_filename;
        std::ofstream m_ostrm;
        int m_width;
        int m_height;

        // Pour éviter les ouverture multiples
        static std::set<std::string> s_openfiles;
};

#endif // SVGFILE_H_INCLUDED



