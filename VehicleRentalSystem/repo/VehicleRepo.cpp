#include "../CommonDepen.h"
#include<map>
#include<vector>

class VehicleRepo{
private:

    map<string , vector<string>> repoList;
    static VehicleRepo* pInstance2;

   VehicleRepo(){
        repoList.insert({"5 Seat" , {"Sedan" , "Hatchback"} });
        repoList.insert({"7 Seat" , {"SUV"}} );
    }
public:
    static VehicleRepo* getInstance(){
        if( pInstance2 == NULL)
        {
            pInstance2 = new VehicleRepo();
        }
        return pInstance2;
    }

    vector<string> getListOfVehicles(string name){
        return repoList[name];
    }
};