late TabController _tabController;

@override

  void initState() {

    super.initState();

    _tabController = TabController(length: 7, vsync: this);

  }

@override

  void dispose() {

    _tabController.dispose();

    super.dispose();

  }

NestedScrollView(

          floatHeaderSlivers: true,

          headerSliverBuilder: (BuildContext context, bool innerBoxIsScrolled) {

            return <Widget>[

              SliverAppBar(

                elevation: 7,

                floating: true,

                pinned: true,

                centerTitle: true,

                title: Container(

                  height: 100,

                  width: 200,

                  child: Image.asset("assets/images/9.png",

                      filterQuality: FilterQuality.low, fit: BoxFit.cover),

                ),

                bottom: TabBar(

                    controller: _tabController,

                    isScrollable: true,

                    onTap: (value) {

                      showPosType = value == 0

                          ? "music"

                          : value == 1

                              ? "poem"

                              : value == 2

                                  ? "lyrics"

                                  : value == 3

                                      ? "story"

                                      : value == 4

                                          ? "painting"

                                          : value == 5

                                              ? "sclupture"

                                              : value == 6

                                                  ? "digitalart"

                                                  : "";

                    },

                    indicatorSize: TabBarIndicatorSize.tab,

                    indicator: UnderlineTabIndicator(

                        borderSide: BorderSide(

                            // color: Colors.white,

                            width: 3)),

                    indicatorPadding:

                        EdgeInsets.only(bottom: 10, left: 10, right: 10),

                    tabs: [

                      Tab(

                          text: "Music",

                          icon: poemUrl.isNotEmpty

                              ? Container(

                                  height: 40,

                                  width: 40,

                                  child: ClipRRect(

                                    child: Image.network(

                                      poemUrl,

                                      fit: BoxFit.cover,

                                    ),

                                  ),

                                )

                              : Icon(EvaIcons.music)),

                      Tab(

                          text: "Poem",

                          icon: poemUrl.isNotEmpty

                              ? Container(

                                  height: 40,

                                  width: 40,

                                  child: ClipRRect(

                                    child: Image.network(

                                      poemUrl,

                                      fit: BoxFit.cover,

                                    ),

                                  ),

                                )

                              : Icon(Icons.microwave)),

                      Tab(

                        text: "Lyrics",

                        icon: digitalartUrl.isNotEmpty

                            ? Container(

                                height: 40,

                                width: 40,

                                child: ClipRRect(

                                  child: Image.network(

                                    digitalartUrl,

                                    fit: BoxFit.cover,

                                  ),

                                ),

                              )

                            : Icon(Icons.library_music_sharp),

                      ),

                      Tab(

                        text: "Story",

                        icon: digitalartUrl.isNotEmpty

                            ? Container(

                                height: 40,

                                width: 40,

                                child: ClipRRect(

                                  child: Image.network(

                                    digitalartUrl,

                                    fit: BoxFit.cover,

                                  ),

                                ),

                              )

                            : Icon(Icons.library_music_sharp),

                      ),

                      Tab(

                        text: "Painting",

                        icon: digitalartUrl.isNotEmpty

                            ? Container(

                                height: 40,

                                width: 40,

                                child: ClipRRect(

                                  child: Image.network(

                                    digitalartUrl,

                                    fit: BoxFit.cover,

                                  ),

                                ),

                              )

                            : Icon(Icons.library_music_sharp),

                      ),

                      Tab(

                        text: "Sclupture",

                        icon: digitalartUrl.isNotEmpty

                            ? Container(

                                height: 40,

                                width: 40,

                                child: ClipRRect(

                                  child: Image.network(

                                    digitalartUrl,

                                    fit: BoxFit.cover,

                                  ),

                                ),

                              )

                            : Icon(Icons.library_music_sharp),

                      ),

                      Tab(

                        text: "Digital Art",

                        icon: digitalartUrl.isNotEmpty

                            ? Container(

                                height: 40,

                                width: 40,

                                child: ClipRRect(

                                  child: Image.network(

                                    digitalartUrl,

                                    fit: BoxFit.cover,

                                  ),

                                ),

                              )

                            : Icon(Icons.microwave),

                      )

                    ]),

                //forceElevated: true,

                //automaticallyImplyLeading: false,

                //

                actions: <Widget>[

                  CircularButton(

                      icon: Icon(Icons.search),

                      onPressed: () {

                        Navigator.pushNamed(context, MyRoutes.searchRoute);

                        // ScaffoldMessenger.of(context).showSnackBar(snackBar);

                      })

                ],

              ),

            ];

          },

          body: TabBarView(controller: _tabController, children: [

//             PaginateFirestore(

//               // Use SliverAppBar in header to make it sticky

//               // item builder type is compulsory.

//               itemBuilderType:

//                   PaginateBuilderType.listView, //Change types accordingly

//               itemBuilder: (index, context, documentSnapshot) {

//                 return Provider.of<FeedHelpers>(context)

//                     .buildCard1(context, documentSnapshot, index);

//               },

//               // orderBy is compulsory to enable pagination

//               query: FirebaseFirestore.instance

//                   .collection("music")

//                   .doc("PoP5urWdLCCPAav5ndze") //"PoP5urWdLCCPAav5ndze"

//                   .collection("docs")

//                   .orderBy("time", descending: true)

//                   .limit(4),

//               isLive: true,

//             ),

//             PaginateFirestore(

//               // Use SliverAppBar in header to make it sticky

//               // item builder type is compulsory.

//               itemBuilderType:

//                   PaginateBuilderType.listView, //Change types accordingly

//               itemBuilder: (index, context, documentSnapshot) {

//                 return Provider.of<FeedHelpers>(context)

//                     .buildCard1(context, documentSnapshot, index);

//               },

//               // orderBy is compulsory to enable pagination

//               query: FirebaseFirestore.instance

//                   .collection("poem")

//                   .doc("PoP5urWdLCCPAav5ndze") //"PoP5urWdLCCPAav5ndze"

//                   .collection("docs")

//                   .orderBy("time", descending: true),

//               // to fetch real-time data

//               isLive: true,

//             ),

//             PaginateFirestore(

//               // Use SliverAppBar in header to make it sticky

//               // item builder type is compulsory.

//               itemBuilderType:

//                   PaginateBuilderType.listView, //Change types accordingly

//               itemBuilder: (index, context, documentSnapshot) {

//                 return Provider.of<FeedHelpers>(context)

//                     .buildCard1(context, documentSnapshot, index);

//               },

//               // orderBy is compulsory to enable pagination

//               query: FirebaseFirestore.instance

//                   .collection("lyrics")

//                   .doc("PoP5urWdLCCPAav5ndze") //"PoP5urWdLCCPAav5ndze"

//                   .collection("docs")

//                   .orderBy("time", descending: true),

//               // to fetch real-time data

//               isLive: true,

//             ),

//             PaginateFirestore(

//               // Use SliverAppBar in header to make it sticky

//               // item builder type is compulsory.

//               itemBuilderType:

//                   PaginateBuilderType.listView, //Change types accordingly

//               itemBuilder: (index, context, documentSnapshot) {

//                 return Provider.of<FeedHelpers>(context)

//                     .buildCard1(context, documentSnapshot, index);

//               },

//               // orderBy is compulsory to enable pagination

//               query: FirebaseFirestore.instance

//                   .collection("story")

//                   .doc("PoP5urWdLCCPAav5ndze") //"PoP5urWdLCCPAav5ndze"

//                   .collection("docs")

//                   .orderBy("time", descending: true),

//               // to fetch real-time data

//               isLive: true,

//             ),

//             PaginateFirestore(

//               // Use SliverAppBar in header to make it sticky

//               // item builder type is compulsory.

//               itemBuilderType:

//                   PaginateBuilderType.listView, //Change types accordingly

//               itemBuilder: (index, context, documentSnapshot) {

//                 return Provider.of<FeedHelpers>(context)

//                     .buildCard1(context, documentSnapshot, index);

//               },

//               // orderBy is compulsory to enable pagination

//               query: FirebaseFirestore.instance

//                   .collection("painting")

//                   .doc("PoP5urWdLCCPAav5ndze") //"PoP5urWdLCCPAav5ndze"

//                   .collection("docs")

//                   .orderBy("time", descending: true),

//               // to fetch real-time data

//               isLive: true,

//             ),

//             PaginateFirestore(

//               // Use SliverAppBar in header to make it sticky

//               // item builder type is compulsory.

//               itemBuilderType:

//                   PaginateBuilderType.listView, //Change types accordingly

//               itemBuilder: (index, context, documentSnapshot) {

//                 return Provider.of<FeedHelpers>(context)

//                     .buildCard1(context, documentSnapshot, index);

//               },

//               // orderBy is compulsory to enable pagination

//               query: FirebaseFirestore.instance

//                   .collection("sclupture")

//                   .doc("PoP5urWdLCCPAav5ndze") //"PoP5urWdLCCPAav5ndze"

//                   .collection("docs")

//                   .orderBy("time", descending: true),

//               // to fetch real-time data

//               isLive: true,

//             ),

//             PaginateFirestore(

//               // Use SliverAppBar in header to make it sticky

//               // item builder type is compulsory.

//               itemBuilderType:

//                   PaginateBuilderType.listView, //Change types accordingly

//               itemBuilder: (index, context, documentSnapshot) {

//                 return Provider.of<FeedHelpers>(context)

//                     .buildCard1(context, documentSnapshot, index);

//               },

//               // orderBy is compulsory to enable pagination

//               query: FirebaseFirestore.instance

//                   .collection("digitalart")

//                   .doc("PoP5urWdLCCPAav5ndze") //"PoP5urWdLCCPAav5ndze"

//                   .collection("docs")

//                   .orderBy("time", descending: true),

//               // to fetch real-time data

//               isLive: true,

//             ),

          ])),
