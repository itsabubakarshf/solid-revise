#include <iostream>

// A bulky interface forcing implementation of unrelated methods
class Media {
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void setNarrationSpeed(float speed) = 0; // Not relevant for all media types
};

// Music class forced to implement all methods, including unrelated ones
class Music : public Media {
public:
    void play() override {
        std::cout << "Music starts playing." << std::endl;
    }
    void pause() override {
        std::cout << "Music paused." << std::endl;
    }
    void stop() override {
        std::cout << "Music stopped." << std::endl;
    }
    // Music doesn't need narration speed, but it's forced to implement this method
    void setNarrationSpeed(float speed) override {
        // Maybe throw an error or just ignore
        std::cout << "Setting narration speed: Not applicable for music." << std::endl;
    }
};

// AudioBook class also implements all methods, including relevant ones
class AudioBook : public Media {
public:
    void play() override {
        std::cout << "Audiobook starts playing." << std::endl;
    }
    void pause() override {
        std::cout << "Audiobook paused." << std::endl;
    }
    void stop() override {
        std::cout << "Audiobook stopped." << std::endl;
    }
    // Narration speed adjustment is relevant for audiobooks
    void setNarrationSpeed(float speed) override {
        std::cout << "Setting narration speed to " << speed << "x." << std::endl;
    }
};

int main() {
    Music myMusic;
    AudioBook myAudioBook;

    // Demonstrating method calls
    myMusic.play();
    myMusic.setNarrationSpeed(1.0); // Irrelevant method for Music

    myAudioBook.play();
    myAudioBook.setNarrationSpeed(1.5); // Relevant and used in AudioBook

    return 0;
}
