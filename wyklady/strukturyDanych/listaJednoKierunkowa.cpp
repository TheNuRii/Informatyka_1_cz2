
using namespace std;

class link {
private:
    double Value;
    link *Next;
};

class list {
protected:
    link *First;
public:
    list() : First(NULL){}
    lis(const list &soure);
    virtual ~list();

    virtual void add(double vale);
    virtual void insert(double Void);
    link* link :: insert(value){
        Next = new link(vale, Next);
        return Next;
    }

    void list :: add(double vale){
        First = new list(vale, First);
    }

};