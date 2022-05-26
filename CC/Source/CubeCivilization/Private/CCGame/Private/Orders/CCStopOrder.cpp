#include "CCGame/Classes/Orders/CCStopOrder.h"
#include "CCGame/Classes/Orders/CCOrderTargetType.h"
#include "CCGame/Classes/Libraries/CCGamePlayTagLibrary.h"

UCCStopOrder::UCCStopOrder(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	TargetType = ECCOrderTargetType::ORDERTARGET_None;
	GroupExecutionType = ECCOrderGroupExecutionType::ORDERGROUPEXECUTION_ALL;

	IssueTagRequirements.SourceBlockedTags.AddTag(UCCGamePlayTagLibrary::Status_Changing_Constructing());
}
