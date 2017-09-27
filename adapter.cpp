/*
 * Adapter Pattern
 *
 * Target
 * Adapter
 * Adaptee
 * Client
 *
 * 就是封装一下原来的产品，
 * 然后提供给用户一个接口让其
 * 使用原来的产品，但是达到用户
 * 想要的效果
 */
#include <iostream>
#include <string>
using namespace std;

/*
 * 抽象基类->实际产品
 */
class AdvencedMediaPlayer
{
    public:
	virtual void playVlc() = 0;
	virtual void playMp4() = 0;
};	
/*
 * 具体某个产品 playVlc() or playMp4()
 * 接口比较个性化，不统一
 */
class VlcPlayer: public AdvencedMediaPlayer
{
    public:
	void playVlc(){ cout<<"Vlc"<<endl; }
	void playMp4(){}
};
class Mp4Player: public AdvencedMediaPlayer
{
    public:
	void playVlc(){}
	void playMp4(){ cout<<"MP4"<<endl; }
};
/*
 * 抽象适配基类->抽象接口 play()
 */
class MediaPlayer
{
    public:
	virtual void play(string& name) = 0;
};
/*
 * 适配器的具体实现
 * 内部实则调用之前的具体产品
 * 只不过提供给用户一个统一的接口 play()
 */
class MediaAdapter: public MediaPlayer
{
    private:
	AdvencedMediaPlayer *media;

    public:
	MediaAdapter(string& name)
	{
	    if (name == "Vlc")
		media = new VlcPlayer();
	    else 
		media = new Mp4Player();
	}
	
	void play(string& name) 
	{
	    if(name == "Vlc")
		media->playVlc();
	    else
		media->playMp4();
	}
};


int main()
{
    string name = "Vlc";
    MediaAdapter adapter(name);
    adapter.play(name);	//使用统一接口，使用比较方便

    return 0;
}
