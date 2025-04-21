SELECT 
    CONCAT(m.memberSurname, ' ', m.memberForename) AS fullMemberName,
    n.narrowDesc AS narrowExpertiseDescription,
    b.broadDesc AS broadExpertiseDescription
FROM 
    member m
JOIN 
    memberNarrow mn ON m.memberId = mn.memberId
JOIN 
    narrow n ON mn.narrowId = n.narrowId
JOIN 
    broad b ON n.narrowBroadId = b.broadId
ORDER BY 
    fullMemberName, 
    narrowExpertiseDescription
