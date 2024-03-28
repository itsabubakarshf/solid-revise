// C++ Example Demonstrating ISP:
// Let's say we're building a digital media system that deals with different types of media, like audio books and music. Not all media types share the same functionalities; for instance, books might have a narration speed control which isn't relevant for music.

// Playing functionalities interface
class Playable {
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
};

// Specific interface for audio books
class AdjustableNarration {
public:
    virtual void setNarrationSpeed(float speed) = 0;
};

// Music class implements only what it needs
class Music : public Playable {
public:
    void play() override {
        // Implementation to start playing music
    }
    void pause() override {
        // Implementation to pause music
    }
    void stop() override {
        // Implementation to stop music
    }
};

// AudioBook class implements both interfaces
class AudioBook : public Playable, public AdjustableNarration {
public:
    void play() override {
        // Implementation to start playing the audiobook
    }
    void pause() override {
        // Implementation to pause the audiobook
    }
    void stop() override {
        // Implementation to stop the audiobook
    }
    void setNarrationSpeed(float speed) override {
        // Implementation to adjust narration speed
    }
};

int main() {
    Music myMusic;
    AudioBook myAudioBook;

    // Use the objects as needed, knowing they only implement what's necessary
    myMusic.play();
    myAudioBook.play();
    myAudioBook.setNarrationSpeed(1.25f); // Adjust speed, something only the audiobook can do

    return 0;
}



// Without ISP, we had a bulky interface forcing all media types to implement methods that might not be relevant to them (like setNarrationSpeed for music).
// With ISP, we split the interface into two: Playable for basic media controls and AdjustableNarration for audiobooks that require speed control. Each class implements only the interfaces that are relevant, making the system cleaner and more flexible.