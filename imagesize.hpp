#pragma once
#include <string>

class IImageSize
{
    protected:
        std::string name;
        IImageSize(std::string name);
        
    public:
        virtual int getHeight() const = 0;
        virtual int getWight() const = 0;
        virtual ~IImageSize() = default;
};

class ImageSizeCalculator : public IImageSize
{
    public:
    ImageSizeCalculator(std::string name);
    int getWight() const override;
    int getHeight() const override;
    virtual ~ImageSizeCalculator() = default;
};

class ImageSizeProxy : public IImageSize
{
    private:
        ImageSizeCalculator *calc;

    public:
        ImageSizeProxy(std::string name);
        ImageSizeProxy(const ImageSizeProxy &isp);
        virtual ~ImageSizeProxy();
        
        int getWight() const override;
        int getHeight() const override;
};

