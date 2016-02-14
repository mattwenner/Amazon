//comparator for sorting products alphabetically
struct AlphaComp {
    bool operator()( Product* lhs, Product* rhs){ 
      return lhs->getName() <= rhs->getName(); 
    }
};

//comparator for sorting products by rating
struct RatingComp{
	bool operator()(Product* lhs, Product* rhs){
		//number of ratings for left hand product
		int lhs_ratings=0;
		double lhs_grand_total=0;
		double lhs_average=0;
		//number of ratings for right hand product
		int rhs_ratings=0;
		double rhs_grand_total=0;
		double rhs_average=0;

		for(unsigned int i=0; i<lhs->getReviews().size(); i++){
			lhs_grand_total+=lhs->getReviews()[i]->rating;
			lhs_ratings++;
		}

		for(unsigned int j=0; j<rhs->getReviews().size(); j++){
			rhs_grand_total+=rhs->getReviews()[j]->rating;
			rhs_ratings++;
		}

		//if there is at least one rating for left hand product
		if(lhs_ratings>0){
			lhs_average= lhs_grand_total/lhs_ratings;
		}

		//if there is at least one rating for right hand product
		if(rhs_ratings>0){
			rhs_average=rhs_grand_total/rhs_ratings;
		}

		return lhs_average>=rhs_average;
	}
};
//comparator for sorting ratings by date
struct DateComp{
	bool operator()(Review* lhs, Review* rhs){

		return lhs->date>rhs->date;
	}
};

