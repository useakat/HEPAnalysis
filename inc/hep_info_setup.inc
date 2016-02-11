// -*- C++ -*-  
   std::cout<<std::endl;
   std::cout<<"  << Flags >>"<<std::endl;
   std::cout<<std::endl;
   std::cout<<"    b-Jets in final states : "<<bFlag<<std::endl;
   std::cout<<std::endl;
   std::cout<<"  << Sigma/Luminosity >>"<<std::endl;
   std::cout<<std::endl;
   std::cout<<"    Sigma Gen [pb]         : "<<sigmaGen<<std::endl;
   std::cout<<std::endl;
   std::cout<<"  << Selection Conditions >>"<<std::endl;
   std::cout<<std::endl;
   std::cout<<"    Leading pT jets        : "<<pTmaxCut<<std::endl;
   std::cout<<"    Mtt cut - 1            : "<<mttCut1<<std::endl;
   std::cout<<"    Mtt cut - 2            : "<<mttCut2<<std::endl;
   std::cout<<std::endl;
   std::cout<<"  << Mass and Width >>"<<std::endl;
   std::cout<<std::endl;
   std::cout<<"    W mass                 : "<<mW<<std::endl;
   std::cout<<"    W width cut            : "<<dMWCut<<std::endl;
   std::cout<<"    t mass                 : "<<mt<<std::endl;
   std::cout<<"    t width cut            : "<<dMtCut<<std::endl;
   std::cout<<std::endl;
   std::cout<<"  << b-Tagging Parameters >>"<<std::endl;
   std::cout<<std::endl;
   std::cout<<"    b-Tagg. Eff.           : "<<effBTag<<std::endl;
   std::cout<<"    mis-b-Tagg. Prob.      : "<<misBTag<<std::endl;
   std::cout<<"    b-Tagg. Enhance Fact.  : "<<bTagEnhanceFactor<<std::endl;
   std::cout<<std::endl;
   
   // List of selections
   std::vector<std::string> selectionList;
   
   selectionList.push_back("Input                : ");
   selectionList.push_back("Kinematical Cuts     : ");
   selectionList.push_back("Highest Jet pT       : ");
   selectionList.push_back("No. of Jets          : ");
   selectionList.push_back("No. of b-Jets        : ");
   selectionList.push_back("x for W->lv rec.     : ");
   selectionList.push_back("No. of W->jj cand.   : ");
   selectionList.push_back("No. of tt-bar cand.  : ");
