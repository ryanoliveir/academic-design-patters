#include <iostream>
#include <vector>

class Observer;

class YouTubeChannel {
private:
    std::vector<Observer*> subscribers;
    std::string latestVideo;

public:
    void subscribe(Observer* subscriber);
    void unsubscribe(Observer* subscriber);
    void uploadVideo(const std::string& videoTitle);
    const std::string& getLatestVideo() const;
    void notifySubscribers();
};


class Observer {
public:
    virtual void update(const std::string& latestVideo) = 0;
};


class Subscriber : public Observer {
private:
    std::string subscriberName;

public:
    Subscriber(const std::string& name) : subscriberName(name) {}

    void update(const std::string& latestVideo) override {
        std::cout << "Notificacao para " << subscriberName << ": Novo video postado -> " << latestVideo << std::endl;
    }
};


void YouTubeChannel::subscribe(Observer* subscriber) {
    subscribers.push_back(subscriber);
}

void YouTubeChannel::unsubscribe(Observer* subscriber) {
    // Implementação para remover inscrito da lista
}

void YouTubeChannel::uploadVideo(const std::string& videoTitle) {
    latestVideo = videoTitle;
    notifySubscribers();
}

const std::string& YouTubeChannel::getLatestVideo() const {
    return latestVideo;
}

void YouTubeChannel::notifySubscribers() {
    for (Observer* subscriber : subscribers) {
        subscriber->update(getLatestVideo());
    }
}

int main(){

    YouTubeChannel channel;

    Subscriber subscriber1("Ryan");
    Subscriber subscriber2("BoB");

    channel.subscribe(&subscriber1);
    channel.subscribe(&subscriber2);


    channel.uploadVideo("Code with Tim");
}
